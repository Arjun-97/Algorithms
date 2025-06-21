const std = @import("std");
const Allocator = std.mem.Allocator;

pub fn Array(comptime T: type) type {
    return struct {
        items: []T,
        capacity: usize,
        length: usize,
        allocator: Allocator,
        const Self = @This();

        pub fn init(allocator: Allocator, capacity: usize) !Array(T) {
            var buf = try allocator.alloc(T, capacity);
            return .{ .items = buf[0..buf.len], .capacity = capacity, .length = 0, .allocator = allocator };
        }

        pub fn deinit(self: *Self) void {
            self.allocator.free(self.items);
        }

        pub fn append(self: *Self, val: T) !void {
            if ((self.length + 1) == self.capacity) {
                var new_buf = try self.allocator.alloc(T, self.capacity * 2);
                @memcpy(new_buf[0..self.capacity], self.items);
                self.allocator.free(self.items);
                self.items = new_buf;
                self.capacity = self.capacity * 2;
            }
            self.items[self.length] = val;
            self.length += 1;
        }

        pub fn pop(self: *Self) void {
            if (self.length == 0) return;
            self.items[self.length - 1] = undefined;
            self.length -= 1;
        }

        pub fn display(self: Self) void {
            for (self.items[0..self.length]) |i| {
                std.debug.print("{d}\t", .{i});
            }
        }
    };
}

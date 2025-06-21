const std = @import("std");
const array = @import("DynamicArray/array.zig");

fn LinearSearch(arr: array.Array(i32), find: i32) usize {
    for (0..arr.length) |i| {
        if (find == arr.items[i]) {
            return i;
        }
    }
    return arr.length + 1;
}

pub fn main() !void {
    const stdin = std.io.getStdIn().reader();
    const stdout = std.io.getStdOut().writer();
    var buffer: [128]u8 = undefined;

    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();

    const dyn = array.Array(i32);
    var arr = try dyn.init(allocator, 16);
    defer arr.deinit();

    try stdout.print("Enter the elements in the array separated by space: ", .{});
    const line = try stdin.readUntilDelimiterOrEof(&buffer, '\n');

    if (line) |i| {
        var tokenizer = std.mem.tokenizeAny(u8, i, " ");
        while (tokenizer.next()) |token| {
            const num = try std.fmt.parseInt(i32, token, 10);
            try arr.append(num);
        }
    }

    try stdout.print("Enter the element you want to find: ", .{});
    const line2 = try stdin.readUntilDelimiterOrEof(&buffer, '\n');

    if (line2) |i| {
        const query = try std.fmt.parseInt(i32, i, 10);
        const result = LinearSearch(arr, query);

        if (result == arr.length + 1) {
            try stdout.print("Element not found!", .{});
        } else {
            try stdout.print("Element found at index {d}", .{result});
        }
    }
}

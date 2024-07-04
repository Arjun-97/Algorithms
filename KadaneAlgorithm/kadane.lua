function kadane(arr)
	local max_sum = -math.huge
	local current_sum = 0
	local n = #arr

	for i = 1, n do
		current_sum = current_sum  + arr[i]

		if max_sum < current_sum then max_sum = current_sum end
		if current_sum < 0 then current_sum = 0 end
	end

	return max_sum
end

function main()
	io.write("Enter number of elements: ")
	local n = io.read("*n")
	local arr = {}
	
	for i = 1, n do
		io.write("Enter an element: ")
		arr[i] = io.read("*n")
	end

	print("The largest sub array sum is: "..kadane(arr))
end

main()

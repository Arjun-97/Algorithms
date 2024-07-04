function minmax(arr, i, j, max, min)
	local max1, min1
	
	if i == j then
		max, min = arr[i], arr[i]
	elseif i == j - 1 then
		if arr[i] < arr[j] then
			max, min = arr[j], arr[i]
		else
			max, min = arr[i], arr[j]
		end
	else
		local mid = math.floor((i+j)/2)
		min, max = minmax(arr, i, mid, max, min)
		min1, max1 = minmax(arr, mid+1, j, max1, min1)

		if max < max1 then
			max = max1
		end
		
		if min > min1 then
			min = min1
		end
	end
		
	return min, max
end

function main()
	local min, max
	io.write("Enter number of elements: ")
	local n = io.read("*n")
	arr = {}
	for i = 1, n do
		io.write("Enter an element: ")
		arr[i] = io.read("*n")
	end

	min, max = minmax(arr, 1, n, max, min)
	print("Maximum element: "..max)
	print("Minimum element: "..min)
end

main()

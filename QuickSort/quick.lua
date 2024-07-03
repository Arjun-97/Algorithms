function quickSort(arr, p, r)
	if p < r then
		local q = partition(arr, p, r)
		quickSort(arr, p, q - 1)
		quickSort(arr, q + 1, r)
	end
end

function partition(arr, p, r)
	x = arr[r]
	i = p - 1
	for j = p, r - 1 do
		if arr[j] <= x then
			i = i + 1
			arr[i], arr[j] = arr[j], arr[i]
		end
	end
	arr[i+1], arr[r] = arr[r], arr[i+1]
	return i + 1
end

function main()
	io.write("Enter number of elements: ")
	n = io.read("*n")
	arr = {}

	for i = 1, n do
		io.write("Enter an element: ")
		arr[i] = io.read("*n")
	end

	p, r = 1, n

	quickSort(arr, p, r)
	
	print("Sorted array is: ")
	for i = 1, n do
		io.write(arr[i].." ")
	end
end

main()

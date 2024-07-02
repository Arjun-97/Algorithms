function mergeSort(a, p, r)
	if p < r then
		local q = math.floor((p + r) / 2)
		mergeSort(a, p, q)
		mergeSort(a, q+1, r)
		merge(a, p, q, r)
	end
end

function merge(a, p, q, r)
	local n1 = q - p + 1
	local n2 = r - q
	local L, R = {}, {}

	for i = 1, n1 do
		L[i] = a[p + i - 1]
	end

	for j = 1, n2 do
		R[j] = a[j + q]
	end

	L[n1+1], R[n2+1], i, j = math.huge, math.huge, 1, 1

	for k = p, r do
		if L[i] <= R[j] then
			a[k] = L[i]
			i = i + 1
		else 
			a[k] = R[j]
			j = j + 1
		end
	end
end

function main()
	io.write("Enter number of elements: ")
	n = io.read("*n")
	a = {}
	
	for i = 1, n do
		io.write("Enter a number: ")
		a[i] = io.read("*n")
	end

	p, r = 1, n

	mergeSort(a, p, r)

	for i = 1, n do
		io.write(a[i].."  ")
	end
end

main()

function binSearch(arr, find)
    local start, fin = 1, #arr
    local mid = math.floor((start + fin) / 2)

    while start <= fin do
        if find == arr[mid] then
            return mid
        elseif find < arr[mid] then
            fin = mid - 1
            mid = math.floor((start + fin) / 2)
        else
            start = mid + 1
            mid = math.floor((start + fin) / 2)
        end
    end

    return -1
end

function main()
    io.write("Enter number of elements: ")
    local n = io.read("*n")
    local arr = {}

    for i = 1, n do
        io.write("Enter an element: ")
        arr[i] = io.read("*n")
    end

    io.write("Enter an element to search: ")
    local find = io.read("*n")

    table.sort(arr)

    print("Sorted array: ")

    for i = 1, n do
        io.write(arr[i].." ")
    end
    print()

    local ans = binSearch(arr, find)

    if ans == -1 then
        print("Element not found")
    else
        print("Element found at position: "..ans)
    end
end

main()

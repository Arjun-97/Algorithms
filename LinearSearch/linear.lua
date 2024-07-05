function linearSearch(arr, find)
    for i = 1, #arr do
        if arr[i] == find then
            return i
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

    io.write("Enter an element to find: ")
    local find = io.read("*n")

    local ans = linearSearch(arr, find)

    if ans == -1 then
        print("Element not found")
    else
        print("Element found at index: "..ans)
    end
end

main()

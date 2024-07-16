function selectionSort(arr)
    local n = #arr

    for i = 1, n do
        local min = i

        for j = i + 1, n do
            if arr[j] < arr[min] then
                min = j
            end
        end

        arr[i], arr[min] = arr[min], arr[i]
    end
end

function main()
    io.write("Enter number of elements: ")
    local n = io.read("*n")

    local arr = {}

    for i = 1, n do
        io.write("Enter an element: ")
        arr[i] = io.read("*n")
    end

    selectionSort(arr)

    print("Sorted array: ")

    for i = 1, n do
        io.write(arr[i].." ")
    end
end

main()

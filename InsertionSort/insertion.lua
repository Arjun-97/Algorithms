function insertionSort(arr)
    local n = #arr

    for j = 2, n do
        local key = arr[j]
        local i = j - 1

        while i >= 1 and arr[i] > key do
            arr[i + 1] = arr[i]
            i = i - 1
        end
        arr[i + 1] = key;
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

    insertionSort(arr)

    print("Sorted array is: ")

    for i = 1, n do
        io.write(arr[i].." ")
    end
end

main()

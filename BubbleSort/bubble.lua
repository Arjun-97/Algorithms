function bubbleSort(arr)
    local n = #arr
    for i = 1, n - 1 do
        for j = 1, n - i do
            if arr[j] > arr[j+1] then
                arr[j], arr[j+1] = arr[j+1], arr[j]
            end
        end
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

    bubbleSort(arr)

    print("Sorted array: ")

    for _, i in ipairs(arr) do
        io.write(i.." ")
    end
end

main()

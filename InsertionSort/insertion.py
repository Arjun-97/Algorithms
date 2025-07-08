def insert(arr, j):
    for i in range(j-1, -1, -1):
        if arr[i] > arr[i+1]:
            arr[i], arr[i+1] = arr[i+1], arr[i]
        else:
            break

def insertionSort(arr):
    for i in range(len(arr)):
        insert(arr, i)
    return arr

if __name__ == "__main__":
    nums = list(map(int, input("Enter elements of the array (space separated): ").split()))
    s = insertionSort(nums)
    print(f"The sorted array is: {s}")

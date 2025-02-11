def maxSubArraySum(a):
    if len(a) == 0:  # Check if array is empty
        return 0
    else:
        size = len(a)
        max_so_far = a[0]
        curr_max = a[0]

        for i in range (1 , size):
            curr_max = max (a[i], curr_max+a[i])
            max_so_far = max (max_so_far,curr_max)

        return max_so_far

size = int(input("Enter the number of elements: "))
arr = []
for i in range(size):
    num = int(input("Enter element "+str(i+1)+": "))
    arr.append(num)

print ("Maximum contiguous sum is", maxSubArraySum(arr))


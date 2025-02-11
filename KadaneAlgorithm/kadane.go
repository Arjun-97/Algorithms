package main

import (
	"fmt"
)

func kadanesAlgorithm(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	maxSoFar := nums[0]
	maxEndingHere := nums[0]

	for i := 1; i < len(nums); i++ {
		maxEndingHere = max(nums[i], maxEndingHere+nums[i])
		maxSoFar = max(maxSoFar, maxEndingHere)
	}

	return maxSoFar
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n int
	fmt.Print("Enter the length of the array: ")
	fmt.Scan(&n)

	nums := make([]int, n)
	fmt.Printf("Enter %d integers for the array: ", n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}

	result := kadanesAlgorithm(nums)
	fmt.Println("The maximum sum of a contiguous subarray is:", result)
}


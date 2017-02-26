// Binary Search Algorithm
package main

import "fmt"

func binarySearch(array []int, wanted int) bool {
	var low, mid, high int = 0, len(array) / 2, len(array) - 1
	for low <= mid && mid <= high {
		if wanted > array[mid] {
			low = mid + 1
		} else if wanted < array[mid] {
			high = mid - 1
		} else {
			return true
		}
		mid = (low + high) / 2
	}
	return false
}

func main() {
	var array = []int{1, 3, 7, 15, 21, 24, 29, 35, 37, 42}
	var wanted int
	fmt.Println("[+] Binary Search Algorithm")
	fmt.Println("[+] All element of array")
	fmt.Println("\t", array)
	fmt.Print("[?] What are you searching in array: ")
	fmt.Scanf("%d", &wanted)
	fmt.Println(binarySearch(array, wanted))
}

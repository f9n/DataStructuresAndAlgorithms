// Linear Search Algorithm
package main

import "fmt"

func linearSearch(array []int, wanted int) bool {
	var i int = 0
	for i < len(array) && array[i] != wanted {
		i++
	}
	if i == len(array) {
		return false
	} else {
		return true
	}
}

func main() {
	var array = []int{1, 3, 2, 10, 20, 24, 16, 19, 8, 27}
	var wanted int
	fmt.Println("[+] Linear Search Algorithm")
	fmt.Println("[+] All element of array")
	fmt.Println("\t", array)
	fmt.Print("[?] What are you searching in array: ")
	fmt.Scanf("%d", &wanted)
	fmt.Println(linearSearch(array, wanted))
}

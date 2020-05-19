package main

import (
	"fmt"
	"sort"
)

func main() {
	var used = *new([1005]bool)
	var arr = make([]int, 0, 100)
	var count = 0
	var n int
	var num int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&num)
		if !used[num] {
			count++
			used[num] = true
			arr = append(arr, num)
		}
	}

	sort.Ints(arr)
	fmt.Println(count)
	for _, n := range arr {
		fmt.Print(n, " ")
	}
	fmt.Println()
}

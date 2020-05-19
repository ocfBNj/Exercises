package main

import (
	"fmt"
	"sort"
)

var arr = *new([100005]int)

func main() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	sort.Ints(arr[:n])

	for _, i := range arr[:n] {
		fmt.Print(i, " ")
	}
	fmt.Println()
}

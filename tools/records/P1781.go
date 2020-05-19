package main

import (
	"fmt"
	"sort"
)

type T struct {
	number int8
	count string
}

type ST []T

func (p ST) Len() int {
	return len(p)
}

func (p ST) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func (p ST) Less(i, j int) bool {
	if len(p[i].count) > len(p[j].count) {
		return true
	}

	if len(p[i].count) == len(p[j].count) {
		for m := 0; m < len(p[i].count); m++ {
			if p[i].count[m] > p[j].count[m] {
				return true
			} else if p[i].count[m] < p[j].count[m] {
				return false
			}
		}
	}

	return false
}

func main() {
	var n int8
	var count T
	var counts = ST{}

	_, _ = fmt.Scan(&n)

	for i := int8(0); i < n; i++ {
		_, _ = fmt.Scan(&count.count)
		count.number = i + 1
		counts = append(counts, count)
	}

	sort.Sort(counts)
	fmt.Println(counts[0].number)
	fmt.Println(counts[0].count)
}

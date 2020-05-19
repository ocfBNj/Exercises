package main

import (
	"fmt"
	"sort"
)

type Person struct {
	number int
	score  int
}

type PersonSlice []Person

func (p PersonSlice) Len() int {
	return len(p)
}

func (p PersonSlice) Less(i, j int) bool {
	if p[i].score > p[j].score {
		return true
	} else if p[i].score == p[j].score {
		return p[i].number < p[j].number
	}

	return false
}

func (p PersonSlice) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func main() {
	var n, m int
	_, _ = fmt.Scan(&n, &m)

	var minRank = int(float64(m) * 1.5)

	var person Person
	var persons = PersonSlice{}

	for i := 0; i < n; i++ {
		_, _ = fmt.Scan(&person.number, &person.score)
		persons = append(persons, person)
	}

	sort.Sort(persons)

	var count = minRank
	var minScore = persons[minRank-1].score
	for i := minRank; ; i++ {
		if persons[i].score != minScore {
			break
		}
		count++
	}

	fmt.Println(minScore, count)

	for i := 0; i < count; i++ {
		fmt.Println(persons[i].number, persons[i].score)
	}

	fmt.Println()
}

package main

import (
	"fmt"
	"math"
)

const s string = "constant"

func main() {
	fmt.Println(s)

	const n = 500000000
	const d = 3e20 / n

	var v float32 = 0.32

	fmt.Println(d)
	fmt.Println(int64(d))
	fmt.Println(math.Sin(n))
	fmt.Println(v)
}

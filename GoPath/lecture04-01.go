package main

import (
	"fmt"
)

// 常量与运算符

const a int = 1
const b = 'A' // 变量类型省略

const (
	c = a
	d = a + 1
	e = a + 2
)

const f, g, h = 1, "2", "c"

const (
	i, j, k = 1, 2, 3
)

const sss = "narlc"
const (
	r = "narglc yu"
	s = len(r) // len() 内置函数
)

const (
	ab, cd = 1, "mmm"
	ef, gh // 每一行变量数必须一样，向上对齐
)

const (
	x = 1
	y // 默认值与第一个对齐
	z
)

// 枚举
const (
	MONDAY = iota
	TUESDAY
	WENDESDAY
)

func main() {
	fmt.Println("x:", x)
	fmt.Println("y:", y)
	fmt.Println("z:", z)
	fmt.Println("s:", s)

	fmt.Printf("ef:%d,gh: %s", ef, gh)

}

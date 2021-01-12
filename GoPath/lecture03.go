package main

import (
	. "fmt"
	"math"
)

// 功能类似 typedef
type (
	BYTE     int8
	WORD     int32
	ByteSize int64
	文本       string
)

func main() {
	// 零值
	var a int
	Println("a int:", a)

	var b float32
	Println("b float32:", b)

	var c bool
	Println("c bool:", c)

	var s string
	Println("s string:", s)

	var sl [1]byte
	Println("sl arr byte:", sl)

	Println("min int8:", math.MinInt8)

	// 3. 声明与赋值
	// method 1
	var str 文本
	str = "中文类型名"

	// method 2
	var b1 int = 1

	// method 3
	var c1 = 321

	// method 4 ->变量声明与赋值的最简写法
	d1 := 456

	// 4. 多个变量的声明与赋值
	var x, y, z int = 1, 2, 3
	// 或
	var x, y, z = 1, 2, 3
	// 或
	x, y, z := 1, 2, 3

	a, _, c, d := 1, 2, 3, 4

	// 类型转换
	var f float32 = 100.3
	b := int(f)

}

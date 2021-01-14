package main

import (
	"fmt"
)

// 使用枚举iota与位运算符表示计算机存储单位
const (
	B float64 = 1 << (iota * 10)
	KB
	MB
	GB
	TB
	PB
)

func main() {
	// 指针操作
	a := 328
	a++ // ++,-- 为单独的一个语句
	var p *int = &a
	fmt.Println(p)
	fmt.Println(*p)

	// if 支持初始化
	if a := 3; a > 1 { // a 只在if语句块有效
		fmt.Println(a)
	}
	fmt.Println(a)

	// 循环语句 for
	x := 1
	// 第一种形式
	for {
		x++
		if x > 3 {
			break
		}
		fmt.Println(x)
	}
	fmt.Println("Over, and x=", x)

	// 第二种形式
	for x <= 6 {
		x++
		fmt.Println(x)
	}
	fmt.Println("Over, and x=", x)

	// 第三种形式
	name := "narglc"
	maxLen := len(name)
	for i := 0; i < maxLen; i++ {
		x++
		fmt.Println(x)
	}
	fmt.Println("Over, and x=", x)

	// switch 语句
	y := 1
	// 第一种形式
	switch y {
	case 0:
		fmt.Println("a=0")
	case 1:
		fmt.Println("a=1")
	default:
		fmt.Println("None")
	}

	// 第二种形式
	a = 1
	fmt.Println("-----------------")
	switch {
	case a >= 0:
		fmt.Println("a=0")
		fallthrough // 继续检查下一个case
	case a >= 1:
		fmt.Println("a=1")
	default:
		fmt.Println("None")
	}

	// 第三种形式
	fmt.Println("-----------------")
	switch testNum := 1; {
	case testNum >= 0:
		fmt.Println("testNum = 0")
		fallthrough // 继续检查下一个case
	case testNum >= 1:
		fmt.Println("testNum = 1")
	default:
		fmt.Println("testNum None")
	}

	// 跳转语句
	// break
LABEL1:
	for {
		for {
			for i := 0; i < 10; i++ {
				if i > 3 {
					break LABEL1
				}
			}
		}
	}
	fmt.Println("jump out loop.")

LABEL2:
	for i := 0; i < 10; i++ {
		for {
			continue LABEL2
			fmt.Println("永远不会执行到")
		}
	}
	fmt.Println("jump out loop of continue.")

LABEL3:
	for i := 0; i < 10; i++ {
		for {
			fmt.Println(i)
			continue LABEL3
		}
	}

}

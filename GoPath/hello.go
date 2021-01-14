package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println("hello, the android phone.")

	var a float32 = 100.3
	println(a)
	b := int(a)
	println(b)

	var s int = 65
	str := string(s)
	println(str)

	var d int = 66
	e := strconv.Itoa(d) // 转为 “66” 字符串
	fmt.Println(e)
	var f int
	f, _ = strconv.Atoi(e) // 转为整数 int
	fmt.Println(f)
}

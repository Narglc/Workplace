package main

import (
	"fmt"
)

func main() {
	// array 数组
	var a [2]int
	var b [2]int
	b = a
	fmt.Println(b)

	var c [3]string
	fmt.Println(c)

	d := [2]int{}
	e := [3]int{1, 3, 5}
	f := [3]int{1, 2}            // 剩余值使用零值补充
	g := [20]int{19: 1}          // 使用索引将idx=19的值赋值为1
	或 := [...]int{1, 2, 3, 4, 5} //不指定数组长度
	者 := [...]int{1: 3, 3: 5, 6: 9, 19: 1}
	fmt.Println("d:", d)
	fmt.Println("e:", e)
	fmt.Println("f:", f)
	fmt.Println("g:", g)
	fmt.Println("或:", 或)
	fmt.Println("者:", 者)

	// 指向数组的指针 VS 指向指针的数组
	fmt.Println("指向数组的指针")
	r := [...]int{99: 1}
	var p *[100]int = &r
	fmt.Println(p)

	fmt.Println("指向指针的数组")
	x, y := 4, 23
	ptr := [...]*int{&x, &y}
	fmt.Println(ptr)

	// 数组的比较 支持相同类型之间的==、!=
	a1 := [2]int{3, 4}
	b1 := [...]int{1, 2}
	fmt.Println("a1==b1? ", a1 == b1)

	// 使用new创建数组，返回指向数组的指针
	p1 := new([10]int)
	p1[1] = 2
	fmt.Println(p1)
	// 等价于
	arr := [10]int{}
	arr[1] = 2
	fmt.Println(arr)

	// 多维数组
	binaryArr := [...][3]int{
		{1, 1, 1},
		{2, 2, 2},
		{2: 4},
		{1: 3},
		{9}}
	fmt.Println(binaryArr)
}

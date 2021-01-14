package main

import (
	"fmt"
)

// 运算符
func main() {
	// <<，>>
	fmt.Println(1 << 10 << 10 >> 10) // 从左往右

	// 位运算符  & ｜ ^(异或) &^
	/*
	    6: 0110
	   11: 1011
	   ----------
	   &	0010 = 2
	   |	1111 = 15
	   ^	1101 = 13
	   &^	0100 = 4
	*/
	fmt.Println("6&11=", 6&11)
	fmt.Println("6|11=", 6|11)
	fmt.Println("6^11=", 6^11)
	fmt.Println("6&^11=", 6&^11)

	// 短路与
	a := 0
	if a > 0 && (10/a) > 1 {
		fmt.Println("OK")
	}

}

package main

import (
	"fmt"
)

func main() {
	a := [...]int{10,3,66,23,33,9,5, 2, 6, 3, 9}
	fmt.Println("orig: ", a)

	Len:=len(a)
	fmt.Println("len(a)=",Len)
	for i:=0;i<Len;i++ {
		for j:=0;j<Len-1-i;j++ {
		    if a[j] > a[j+1] {
				tmp:= a[j]
				a[j]=a[j+1]
				a[j+1]=tmp
			}
		}
		fmt.Println("->",a)
	}
	fmt.Println("after: ",a)
}

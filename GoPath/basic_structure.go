// 当前程序的包名
package main

// 导入其它的包
//import "fmt"

// 别名都使用
import std "fmt"

// 省略调用,不能和别名同时使用
//import . "fmt"

// 一次行导入多个包
/*
import (
	"os"
	"strings"
	"time"
)
*/

// 常量的定义
const PI = 3.14

// 全局变量的声明与赋值
var name = "gopher"

// 一般类型声明
type newType int

// 结构的声明
type gopher struct{}

// 接口的声明
type golang interface{}

// 由 main 函数作为程序入口点启动
func main() {
	std.Println("hello, the android phone.")

}
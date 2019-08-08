#coding:utf-8

# 一刷
print("Hello World!")

# 二刷
x=input("pls input x:")
y=input("pls input y:")

x = int(x)
y = int(y)

if(x == 0 or y == 0):
	res = "在坐标轴上"
elif(x > 0 and y > 0):
	res = "在第一象限内"	
elif(x < 0 and y > 0):
	res = "在第二象限内"	
elif(x < 0 and y < 0):
	res = "在第三象限内"	
else:
	res = "在第四象限内"	
print("("+str(x)+","+str(y)+")"+res)

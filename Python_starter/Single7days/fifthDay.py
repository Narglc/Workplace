#coding:utf-8

# 一刷
def firstBrush():
	for x in range(0,6):
		print("%d line."%x)
	while(x):
		print("-- %d"%x)
		x = x - 1

# 二刷
def add(a = 328, b = 423):
	return a+b
def secondBruch():
	print("add(a)=%d"%add(100))
	print("add()=%d"%add())
	print("add(b=100)=%d"%add(b=100))
	print("add(a=100,b=100)=%d"%add(a=100,b=100))
	print("add(b=100,a=100)=%d"%add(b=100,a=100))
	print("add(200,100)=%d"%add(200,100))
	
# 三刷
def dict_demo():
	dict_1 = {"name":"El Amor En Los Tiempos Del Colera",
			  "author":"Marquez","price":32.8,"Type":"novel"}
	print(type(dict_1))
	print(dict_1["price"])
	for key,value in dict_1.items():
		print(key,value)



if __name__ == '__main__':
	firstBrush()
	secondBruch()
	dict_demo() 

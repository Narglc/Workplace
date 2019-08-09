#coding:utf-8

#一刷
def firstEx():
	x = input("pls input a num:")
	print("数字:%d"%x)
	print("字符:%s"%("just for test."))
	print("另一种字符:"+"another string.")
	y = input("pls input another num:")
	print("计算式:%d"%(x+y))
	print("x>y:%d"%(x>y))
	print("%s输出%d个不同的值并比较x==y?%d"%("一次",3,x==y))

	# 换行符
	for x in range(0,6):
		print(x)#end = " ") #end用法仅适用于python3，python2无法适用

#二刷
from random import randint
def guess_the_number():
	num = randint(0,100)
	print("Guess what I think, you have ten Try.")
	i = 1
	while(i<=10):
		x = int(input("pls input the num you think:"))
		if(x>num):
			print("Bigger!")
		elif(x<num):
			print("Smaller!")
		else:
			print("Congratulations!!! You guess the number.")
			break
		print( "and you have %d %s left."%(10-i,"time" if i>8 else "times"))
		i = i + 1
	if(i == 10):
		print("Game Over!")

def play():
	while(True):
		print("---------------ONE MORE TIME---------------")
		guess_the_number()

#三刷
def read_and_write_file():
	i = 1
	with open("faq.c") as f_read:
		for line in f_read:
			with open("%d.log"%i,'w') as f_write:
				f_write.write(line.strip())
			i = i+1


if __name__ == '__main__':
	firstEx()
	read_and_write_file()
	play()
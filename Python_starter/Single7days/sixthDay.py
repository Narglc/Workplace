#coding:utf-8

# 一刷
def str_and_num():
	print('"Hello World..."')
	print('\'Hello World...\'')
	print("'Hello World...'")
	print("""\t\t\tsouth
			of
			America""")
	print("Area is %.3f and capital %s"%(96000000.328917,'Beijing'))

# 二刷
def list_demo():
	nar_list = ["beijing","shangai","guangzhou","shenzhen","chengdu","hangzhou"]
	print("third data is "+nar_list[2])
	print("where I lived: ",nar_list[3:5])

# 三刷
global count
count = 0
def count_up():
	global count
	count = count + 1
def global_demo():
	#global count
	for x in range(1,13):
		count_up()
	print("fun->count_up was call_backed %d times."%count)

if __name__ == "__main__":
	str_and_num()
	list_demo()
	global_demo()

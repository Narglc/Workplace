#coding:utf-8

# 一刷
def first():
	flag = True
	if(flag == True):
		print("is True")
	num = 423
	print(">328" if num >328 else "<328")

# 二刷
def add(a, b):
	return a+b
def second_fun():
	print(add(328,423))

# 三刷
def file_except():
	file_name = "no_this_file"
	try:
		with open(file_name) as f_obj:
			print(f_obj.readlines())
	except: #IOError:
		print("file %s not exist..."%file_name)


if __name__ == "__main__":
	first()
	second_fun()
	file_except()

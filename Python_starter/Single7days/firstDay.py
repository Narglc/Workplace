#coding:utf-8

# 一刷
print("Hello World!")

# 二刷
def whereThePoint():
	x=raw_input("pls input x:")
	y=raw_input("pls input y:")
	try:
		x = int(x)
		y = int(y)
	except ValueError:
		print("请输入正确的数值!!!")
	else:
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

# 三刷
def splitASentences(sentence):
	# senList = sentence.split(' ')
	index = 0
	leftIndex = 0
	list = []
	for each in sentence:
		#print each
		if each == " ":
			#print(leftIndex,index,sentence[leftIndex:index])
			list.append(sentence[leftIndex:index])
			index = index + 1
			leftIndex = index
		else:
			index = index + 1
	list.append(sentence[leftIndex:])
	return list

def joinToASentences(list):
	# sentence = " ".join(list)
	sentence = ""
	for each in list:
		sentence =  sentence + each + " "
	return sentence[:-1]

if __name__ =="__main__":
	# 二刷测试
	count = 0
	while(count<1):
		whereThePoint()
		count = count + 1
	# 三刷测试
	sentence = "I am not an gooooood coder"
	list1 = splitASentences(sentence)
	print('list is:')
	print(list1)
	print("sentence is:")
	print(joinToASentences(list1))

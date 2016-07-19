#--coding:utf-8--
import random
num=random.randint(0,999)  
#print num

print"""
	有一个0-999之间的整数，
	你需要在10次机会猜中它，
	否则游戏将Game Over！！
	"""
off=0

a=[1,2,3,4,5,6,7,8,9,10]
for x in a:
	print "第%d次机会" %x,
#	guess=int(raw_input("这个数是："))
	guess=input("这个数是：")
#	guess=21
#	print guess
#	print num
	if guess>num:
		print "你所猜的数大了！"
	elif guess<num:
		print "你所猜的数小了！"
	else:
		print "您答对了,恭喜你获得了奖品!"
		off=1
		break
if off==0:
	print "Game Over！"
	print "这个数是：%d"%num






#coding:utf-8

global html
html= 'http://wthrcdn.etouch.cn/weather_mini?city='

from random import randint
import math
import requests				

# 一刷
def gen_random():
	x = randint(1,100)
	print("random num:"+str(x))

def test_math():
	max = pow(12,2)
	print("pow(12,2)::"+str(max))

def first():
	gen_random()
	test_math()

# 二刷
def list_demo():
	nar_list = ["beijing","shangai","guangzhou","shenzhen","chengdu","hangzhou"]
	print("third data is "+nar_list[2])
	print("where I lived: ",nar_list[3:5])
	nar_list.append("shijiazhuang")
	print(nar_list)
	nar_list.remove("beijing")
	print(nar_list)
	del nar_list[1]
	print(nar_list)


# 三刷
def search_weather(str):
	global html
	req = requests.get(html+str)
	req.encoding = 'utf-8'
	print(req.text)
	dict_city = req.json()
	print("------------")
	print(dict_city['data'])


if __name__ == "__main__":
	first()
	list_demo()
	search_weather('北京')

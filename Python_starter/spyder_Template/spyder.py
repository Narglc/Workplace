#coding:utf-8
import urllib

def callback(a,b,c):
	had_pass=100.0*a*b/c

	if had_pass>100:
		had_pass=100
	print "%.2f%%"%had_pass


url="http://www.baidu.com"
html=urllib.urlopen(url)
cont=html.read()
print cont

urllib.urlretrieve(url,'test.txt',callback)


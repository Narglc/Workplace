#coding:utf-8
#自动版
#煎蛋妹子圖專用

import urllib
import urllib2
import re
import time

def getHtml(url):
    user_agent = 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
    headers = {'User-Agent': user_agent,
               'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'}
    req = urllib2.Request(url, headers=headers)
    page = urllib2.urlopen(req)                      #there is the "urllib2"
    html = page.read()
    return html

def getImg(html):
#    reg = r'src="(.+?\.jpg)"'
#    imgre = re.compile(reg)
    imglist = re.findall(r'src="(.+?\.jpg)"', html)
    return imglist

def downloadImg(imglist,x,total):
    i=1
    for imgurl in imglist:
        urllib.urlretrieve(imgurl,'Jiandan/New-%s.jpg'%x)
        print '第%d张已下载！==>%d/%d=%d%%'%(x,i,total,100*i/total)         #百分号使用两个%表示
        x+=1
        i+=1
    return x

page=input("请输入你要下载的图片所在网页的页码:")
num=input("请输入你要下载的页数：")
page_end=page-num
x = 1
imglist=[]
myurl="http://jandan.net/ooxx/page-1844#comments"          ##1853<--1829g
for i in range(page,page_end,-1):
    print i
    url="http://jandan.net/ooxx/page-"+str(i)+"#comments"
    print url
    context = getHtml(url)
    imglist+=getImg(context)
    print "第%d頁網頁的imglist已經加載！共有%d张图片"%(i,len(imglist))
    time.sleep(6)
print imglist
total = len(imglist)
print "共有%d張圖片要下載"%total
downloadImg(imglist,x,total)
print "%d-%d頁下载完毕！"%(page_end+1,page)
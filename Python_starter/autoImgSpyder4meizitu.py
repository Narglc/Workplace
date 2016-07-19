#coding:utf-8

#自動版
#http://www.meizitu.com/ 網頁專用

import urllib
import urllib2
import re

def getHtml(url):
    user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
    headers = {'User-Agent': user_agent}
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
        urllib.urlretrieve(imgurl,'Jiandan/pic-%s.jpg'%x)
        print '第%d张已下载！==>%d/%d=%d%%'%(x,i,total,100*i/total)         #百分号使用两个%表示
        x+=1
        i+=1
    return x

def deleteSameItem(list):
    list4=[]
    for i in list:
        if not i in list4:
            list4.append(i)
    return list4

page=input("请输入你要下载的图片所在网页的页码:")
num=input("请输入你要下载的页数：")
page_end=page-num
x = 1
imglist=[]
myurl="http://www.meizitu.com/a/5185.html"
for i in range(page,page_end,-1):
    url=re.sub(".com/a/(.*?).html",str(i),myurl)     #re.sub 换页
    context = getHtml(url)    #1511
    imglist+=getImg(context)
    print "第%d頁網頁的imglist已經加載！"%i
    print imglist
    print len(imglist)

#print imglist
imglist=deleteSameItem(imglist)
print imglist
total = len(imglist)
print "共有%d張圖片要下載"%total
downloadImg(imglist,x,total)
print "%d-%d頁下载完毕！"%(page_end+1,page)


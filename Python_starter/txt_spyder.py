#coding:gbk

#该网页主要用于爬取天涯博客的文章，先是爬取html

import urllib
import urllib2
import re

def getHtml(url):
    user_agent = 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.85 Safari/537.36'
    headers = {'User-Agent': user_agent}
    req = urllib2.Request(url, headers=headers)
    page = urllib2.urlopen(req)                     
    html = page.read()
    return html

def getHtml(html):                          
    imglist = re.findall(r'href="(.*?\.shtml)" target=', html)
    return imglist

def downloadHtml(imglist,x,total):
    i=1
    for imgurl in imglist:
        urllib.urlretrieve(imgurl,'e://Nar//sources_for_spyder//blog//%s.html'%x)
        print '第%d篇已下载！==>%d/%d=%d%%'%(x,i,total,100*i/total)         #百分号使用两个%表示
        x+=1
        i+=1
    return x
x=1
myurl="http://blog.tianya.cn/listcate-773339-0-1.shtml"
#for i in range(page,page_end,-1):
#myurl=re.sub("page-(.*?)#comments",str(i),myurl)     #re.sub 换页
html = getHtml(myurl)    #1511
print html
#txtlist=getHtml(html)
#print txtlist
#print imglist
#total = len(imglist)
#downloadImg(imglist, x, total)
#print '%d张图片已下载完毕'%total
#print "第%d页已下载完毕"%page

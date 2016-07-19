#coding:utf-8

'''存在严重的编码问题'''


import urllib
import urllib2
import re

def getHtml(url):
    user_agent = 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.125 Safari/537.36'
    headers = {'User-Agent': user_agent}
    req = urllib2.Request(url, headers=headers)
    page = urllib2.urlopen(req)
    html = page.read()
    return html

def getImpart(html):
    reg = r'var SHARINGINFO = {(.+?)};'
    imgre = re.compile(reg,re.DOTALL)
    imglist = re.findall(imgre, html)
    return cont

def getImgName(html):
    reg = r'<div class="edtext pl">(.+?)</div>'
    namegre = re.compile(reg,re.DOTALL)       #包括换行符
    namelist = re.findall(namegre,html)
    return imgnamelist

html = getHtml("http://www.douban.com/photos/album/78049275/")     #当前页码为爬取
print html
print "==============================================================================================="
cont = getImpart(html)
print cont
# x=1
# for imgurl in imglist:
#     urllib.urlretrieve(imgurl,'%d.jpg'%x)
#     x+=1
#
#

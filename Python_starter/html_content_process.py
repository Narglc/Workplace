#coding:utf-8

from common_pic_spider_V1 import *
'''
半自动爬虫
爬去某一网站上所有的.jpg文件


import urllib
import urllib2
import re
import os

def getHtml(url):
#     user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
    user_agent = 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.125 Safari/537.36'
    headers = {'User-Agent': user_agent}
    req = urllib2.Request(url, headers=headers)
    page = urllib2.urlopen(req)
    html = page.read()
    return html

def saveSingleHtmlContent(htmlContent,fileNameToSaveHtmlContent):
    with open(fileNameToSaveHtmlContent,"w") as f_obj:
        f_obj.write(htmlContent)

def find_page_name(content):
    reg = r'<title>(.+?)</title>'
    namere = re.compile(reg)
    page_name = re.findall(namere, content)
    return page_name[0]


def find_page_comment_num(content):
    regOuter = r'"/>赞(.+?)class="action action-rewards"'
    reward_outer_re = re.compile(regOuter)
    reward_outer = re.findall(reward_outer_re,content)

    regInner = r'<span>(.+?)</span>'
    rewardre = re.compile(regInner)
    reward_num = re.findall(rewardre,reward_outer[0])

    return "【"+reward_num[0]+"】"+"-点赞"
'''


url = "http://www.shdsex.xyz/dmvy4-812988.asp"
html = getHtml(url)
#saveSingleHtmlContent(html,"shdsex123.log")
allPicList = getAllImg(html)
picSaveFoldor = find_page_name(html)
saveFileName = "shdsex.log"
saveAllPicListInTheFile(allPicList, saveFileName, picSaveFoldor)
downPicsInSuchDir(allPicList,picSaveFoldor)
print("Done...")



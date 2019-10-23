#coding:utf-8

'''
半自动爬虫
爬去某一网站上所有的.jpg文件
'''

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

def getGIF(html):
    reg = r'img src="(.+?\.gif)"'
    imgre = re.compile(reg)
    imglist = re.findall(imgre, html)
    return imglist

def getJPG(html):
    reg = r'img src="(.+?\.jpg)"'
    imgre = re.compile(reg)
    imglist = re.findall(imgre, html)
    return imglist

def getAllImg(html):
    jpgList = getJPG(html)
    gifList = getGIF(html)
    return jpgList + gifList

def getMainContent(html):   ## 未成功
    reg = r'<article class ="article-content>"(.+?)</article>'
    contentRe = re.compile(reg)
    mainContent = re.findall(contentRe, html)
    return mainContent

def getPicNamebyUrl(imgUrl):
    nameBegin = imgUrl.rfind("/")
    return imgUrl[nameBegin+1:]

def saveAllPicListInTheFile(allPicList,saveFileName,pageTitle,pageNo =''):
    with open(saveFileName,"a+") as f_obj:
        if(pageNo ==''):
            f_obj.write("-----------------------"+pageTitle+"-----------------------\n")
        for each in allPicList:
            f_obj.write(each+'\n')
#        f_obj.write("-----------------------end-----------------------\n")

def saveSingleHtmlContent(htmlContent,fileNameToSaveHtmlContent):
    with open(fileNameToSaveHtmlContent,"w") as f_obj:
        f_obj.write(htmlContent)

def mkDirOrNot(picSaveFoldor):
    if(picSaveFoldor.find('/') != -1):
        pair_path = picSaveFoldor.rfind('/')
        outerPath = picSaveFoldor[:pair_path]
        picSaveFoldor = picSaveFoldor[pair_path+1:]
        os.chdir(outerPath)
    if(not os.path.isdir(picSaveFoldor)):
        os.mkdir(picSaveFoldor)

def downPicsInSuchDir(allPicList,picSaveFoldor):
    total=len(allPicList)
    i=0
    mkDirOrNot(picSaveFoldor)
    print("%d张图片已放入《%s》中。"%(total,picSaveFoldor))
    for imgurl in allPicList:
        urllib.urlretrieve(imgurl,picSaveFoldor+'/'+getPicNamebyUrl(imgurl))
        i += 1
        print '第%d张已下载！==>%d/%d=%d%%' % (i, i, total, 100 * i / total)  # 百分号使用两个%表示
    print "共下载了%d张美图!" % i

def find_page_name(content):
    reg = r'<title>(.+?)</title>'
    namere = re.compile(reg)
    page_name = re.findall(namere, content)
    return page_name[0]

def find_page_reward_num(content):
    regOuter = r'"/>赞(.+?)class="action action-rewards"'
    reward_outer_re = re.compile(regOuter)
    reward_outer = re.findall(reward_outer_re,content)

    regInner = r'<span>(.+?)</span>'
    rewardre = re.compile(regInner)
    reward_num = re.findall(rewardre,reward_outer[0])
    return reward_num[0]

def getStringWithRewardNum(reward_num):
    return "【"+str(reward_num)+"】"+"-点赞"

def spiderOneVolume(Number,saveFileName,pathPicPut):
    for pageNo in ['','/2']:
        urlAddress = "https://fulibus.net/2019"+("%.3d"%Number)+".html"+pageNo
        html = getHtml(urlAddress)
        #article_content = getMainContent(html)
        allPicList = getAllImg(html)
        picSaveFoldor = find_page_name(html)
        reward_num = find_page_reward_num(html)
        saveAllPicListInTheFile(allPicList, saveFileName, picSaveFoldor+getStringWithRewardNum(reward_num), pageNo)
        print(urlAddress+" --got here...")
        downPicsInSuchDir(allPicList, pathPicPut+reward_num+"-"+picSaveFoldor)


if __name__ == "__main__":
    saveFileName = "fulibus_all_pics.log"
    pathPicPut = "/Users/narglc/Downloads/spyder_pics/fulibus/"
    for pageNo in range(144,145):
        Number = pageNo
        spiderOneVolume(Number,saveFileName,pathPicPut)


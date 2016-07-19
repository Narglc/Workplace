#coding:utf-8

'''
半自动爬虫
爬去某一网站上所有的.jpg文件
'''

import urllib
import urllib2
import re


page_context='''</font><div></div></div></div></div><div id="imgContent" class="imgContent noshow"><img class="c_0" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9df87e705.jpg"><img class="c_1" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9dfecf9d5.jpg"><img class="c_2" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e01361c7.jpg"><img class="c_3" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e037032c.jpg"><img class="c_4" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e0c7e827.jpg"><img class="c_5" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e119b4ed.jpg"><img class="c_6" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e1533790.jpg"><img class="c_7" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e1cb4f84.jpg"><img class="c_8" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e24b6ee2.jpg"><img class="c_9" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e26ce2ba.jpg"><img class="c_10" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e28e8a18.jpg"><img class="c_11" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e3490c40.jpg"><img class="c_12" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e3986ab5.jpg"><img class="c_13" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e3ba5686.jpg"><img class="c_14" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e3d9ff13.jpg"><img class="c_15" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e3fb7d83.jpg"><img class="c_16" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e41c4e5b.jpg"><img class="c_17" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e43b634d.jpg"><img class="c_18" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e4720cce.jpg"><img class="c_19" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e4f776d9.jpg"><img class="c_20" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e51725a9.jpg"><img class="c_21" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e536cf9d.jpg"><img class="c_22" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e556e3fa.jpg"><img class="c_23" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e588cdd6.jpg"><img class="c_24" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e5d86dee.jpg"><img class="c_25" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e5fa32fb.jpg"><img class="c_26" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e619e767.jpg"><img class="c_27" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e66a5c17.jpg"><img class="c_28" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e6b9977f.jpg"><img class="c_29" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e70909f9.jpg"><img class="c_30" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e76ee893.jpg"><img class="c_31" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e7c04c0c.jpg"><img class="c_32" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e80edd3d.jpg"><img class="c_33" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e82dd71d.jpg"><img class="c_34" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e84ce529.jpg"><img class="c_35" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e89c0ed8.jpg"><img class="c_36" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e8bb0a88.jpg"><img class="c_37" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e90ce7d8.jpg"><img class="c_38" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e95c3006.jpg"><img class="c_39" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e97b7d4a.jpg"><img class="c_40" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9e9cb4da8.jpg"><img class="c_41" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ea1a9ec8.jpg"><img class="c_42" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ea5134b7.jpg"><img class="c_43" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ea703a2b.jpg"><img class="c_44" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ea92bba4.jpg"><img class="c_45" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9eab68f52.jpg"><img class="c_46" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9eadae657.jpg"><img class="c_47" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9eafe0e71.jpg"><img class="c_48" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9eb50e3db.jpg"><img class="c_49" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9eb701b32.jpg"><img class="c_50" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ebaa0ce1.jpg"><img class="c_51" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ec596f8d.jpg"><img class="c_52" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ec81243b.jpg"><img class="c_53" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ecb479b2.jpg"><img class="c_54" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ed03fe30.jpg"><img class="c_55" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ed39418c.jpg"><img class="c_56" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ed6e189d.jpg"><img class="c_57" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9edc3ae17.jpg"><img class="c_58" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ede35a90.jpg"><img class="c_59" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ee02b3af.jpg"><img class="c_60" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ee595d46.jpg"><img class="c_61" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9eeabab1b.jpg"><img class="c_62" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9eee0fc70.jpg"><img class="c_63" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ef332abe.jpg"><img class="c_64" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9ef8a1bc8.jpg"><img class="c_65" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9efbb1c0d.jpg"><img class="c_66" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f01015db.jpg"><img class="c_67" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f0718835.jpg"><img class="c_68" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f0c28202.jpg"><img class="c_69" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f0e60105.jpg"><img class="c_70" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f14e66d3.jpg"><img class="c_71" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f16d5439.jpg"><img class="c_72" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f1c06a08.jpg"><img class="c_73" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f1e08aec.jpg"><img class="c_74" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f20147b4.jpg"><img class="c_75" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f2b1dd42.jpg"><img class="c_76" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f2deb9a3.jpg"><img class="c_77" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f3027c7e.jpg"><img class="c_78" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f35a1d6b.jpg"><img class="c_79" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f37e5b75.jpg"><img class="c_80" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f39ee65e.jpg"><img class="c_81" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f3c14b11.jpg"><img class="c_82" src="http://pic.xiudoudy.com/Uploads/news/2015-12-24/567b9f3e0be21.jpg"></div></div></div><div class="clearfix"></div><ul class="list-fun "><li class="had-'''


def getHtml(url):
#     user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
    user_agent = 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/43.0.2357.125 Safari/537.36'
    headers = {'User-Agent': user_agent}
    req = urllib2.Request(url, headers=headers)
    page = urllib2.urlopen(req)                      #there is the   "urllib2"
    html = page.read()
    return html

def getImg(html):
#    reg = r'data-url="(.+?\.jpg)"'
    reg = r'src="(.+?\.jpg)"'
#    reg = r'data-original="(.+?\.jpg)"'     #H—pics
    imgre = re.compile(reg)
    imglist = re.findall(imgre, html)
    return imglist

#html = getHtml("http://www.chaoyt.com/article-show-id-361679.html")    #H-pics
#html = getHtml("http://jandan.net/ooxx/page-1853#comments")     #当前页码为爬取
#html=getHtml("http://www.gg1b.com/article-show-id-382166.html")
#html=getHtml("http://www.46hi.com/html/article/222437.html")
html=getHtml("http://bbs.hupu.com/5047156.html")

#imglist=getImg(page)
imglist=getImg(page_context)
print imglist
total=len(imglist)
#x = 2616
x = 1
i=0
for imgurl in imglist:
    urllib.urlretrieve(imgurl,'test/%s.jpg'%x)
#     urllib.urlretrieve(imgurl,'//home//narglc//workspace//eclipse//PyDevTest//test//%s.jpg'%x)
    i+=1
    print '第%d张已下载！==>%d/%d=%d%%'%(x,i,total,100*i/total)         #百分号使用两个%表示
    x+=1
print "共下载了%d张美图!"%i
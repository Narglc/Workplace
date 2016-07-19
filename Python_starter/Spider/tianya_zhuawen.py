#coding:utf-8

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

myurl="http://blog.tianya.cn/listcate-773339-0-1.shtml"
html = getHtml(myurl)
#print html

'''<a href="http://blog.tianya.cn/post-773339-104664588-1.shtml" target="_blank">烟酒僧困顿&amp;躁动的心</a>'''
important=re.findall(r"href='(.*?)</a>", html)
print important
urllist = re.findall(r"href='(.*?\.shtml)' target", important)
#txtlist = re.findall(r"href='(.*?\.shtml)' target='_blank'>(.*?)</a>", html)     #可以使用
print txtlist
total = len(txtlist)
x = 1
i = 1
for txthtml in txtlist:
#    urllib.urlretrieve(txthtml,'e://Nar//sources_for_spyder//blog//%s.html'%x)  #urlretrieve不能这样用！！
    cont = urllib.urlopen(txthtml).read()
    # filename = txthtml[22:]
    # open('blog/'+filename,'w').write(content)
    print "========================================================================="
    print "方案二："
    print "文章题目："
    filename=re.findall(r' class="" title="(.*?)">',cont)
    for i in filename:
        print i
        filename1=i
    print "**************************************************************************"
    print "正文部分："
    chi = re.findall(r'class="article-summary articletext" >(.+?)</div>', cont)
    #print chi     #输出'\xe3\x80\x80\xe3\x80\x80' 字符串
    for i in chi:
    #    print i
        i=i+"<BR>"
        pure_chi=re.findall(r'　　　　(.+?)<BR>', i)
        # BRpos=i.find('<BR>')
        # print BRpos
        for j in pure_chi:
            print j
            f=open(filename1+'.txt','a+')
            f.write(j)
            f.write("\n")
            f.close()

    print "第%d篇文章已下载完成!==>%d/%d=%d%%"%(x,i,total,i*100/total)
    x,i = x+1,i+1
print "已完成所有！！"

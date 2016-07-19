#coding:utf-8
#文本爬虫可用，但爬下来的文件名字需要  再正则
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


txtlist = re.findall(r"href='(.*?\.shtml)' target", html)
#txtlist = re.findall(r"href='(.*?\.shtml)' target='_blank'>(.*?)</a>", html)
print txtlist
total = len(txtlist)
x = 1
i = 1
for txthtml in txtlist:
#    urllib.urlretrieve(txthtml,'e://Nar//sources_for_spyder//blog//%s.html'%x)  #urlretrieve不能这样用！！
    content = urllib.urlopen(txthtml).read()
    filename = txthtml[22:]
    open('blog/'+filename,'w').write(content)
    print "第%d篇文章已下载完成!==>%d/%d=%d%%"%(x,i,total,i*100/total)
    x,i = x+1,i+1
print "已完成所有！！"


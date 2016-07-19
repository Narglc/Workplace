#coding:utf-8
import  re
# content = '编码是这样的吗？'
# filename = 'thefirst.txt'I
# open(filename,'w').write(content)
# import urllib


# imglist=[        ]
# print imglist
# total=len(imglist)
# #x = 2616
# x = 652
# i=0
# for imgurl in imglist:
#     urllib.urlretrieve(imgurl,'test/test-%s.jpg'%x)
# #     urllib.urlretrieve(imgurl,'//home//narglc//workspace//eclipse//PyDevTest//test//%s.jpg'%x)
#     i+=1
#     print '第%d张已下载！==>%d/%d=%d%%'%(x,i,total,100*i/total)         #百分号使用两个%表示
#     x+=1
# print "共下载了%d张图!"%i

# content=open('1.shtml')
# cont=content.read()
# print cont
cont='<span class="pos-right gototop"><a href="#">返回顶部</a></span>'

txt = re.findall(r'herf="#">(.*?)</a></span>', cont)
print txt


# content.colse()
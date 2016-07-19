#coding:utf-8

import sys
import urllib
import urllib2
import re

# html = '''
#             var SHARINGINFO = {
#                 title: '【赛里木湖【胶片 】】我们把西瓜放在湖里冰镇，但这不是我们的车子也不是我们的西瓜',
#                 url: 'http://www.douban.com/photos/photo/1707014033/',
#                 pic: 'http://img3.douban.com/view/photo/photo/public/p1707014033.jpg',
#                 desc: '我们把西瓜放在湖里冰镇，但这不是我们的车子也不是我们的西瓜'
#             };
#         '''
#
# cont=[]
# def getImpart(html):
#     reg = r'SHARINGINFO = {(.+?)};'
#     imgre = re.compile(reg)
#     imglist = re.findall(imgre, html)
#     return cont
#
#
# print "==============================================================================================="
# txt = getImpart(html)
# print txt

# print sys.getdefaultencoding()
# text =u"#who#helloworld#a中传说中的超级能量文x#"
# print isinstance(text,unicode)
# txt = re.findall(r'world#a(.*?)x#', text)
# print str(txt)
# print txt.encode('utf-8')

# a = u"这是个中文"
# chinese=[]
# b = re.compile(u"[\u4e00-\u9fa5]{1,2}")
# c = b.findall(a)
# for i in  c:
#     chinese.append(i)
# print chinese
# print u'\u8fd9\u662f'


# source = "s2f程序员杂志一2d3程序员杂志二2d3程序员杂志三2d3程序员杂志四2d3"
# temp = source.decode('utf8')
# xx=u"([/u4e00-/u9fa5]+)"
# print temp
# print xx
# # pattern = re.compile(xx)
# # results =  pattern.findall(temp)
# # for result in results :
# #     print result

web='<a href="http://blog.tianya.cn/post-773339-104664588-1.shtml" class="" title="烟酒僧困顿&amp;躁动的心">烟酒僧困顿&amp;躁动的心</a>'
#    reg = r'src="(.+?\.jpg)"'
#    imgre = re.compile(reg)
cont = re.findall(r'title="(.+?)"', web)
# print cont.encode("utf8")
print cont
for i in cont:
    print i
    con=i.find('酒僧')
    print i[con]

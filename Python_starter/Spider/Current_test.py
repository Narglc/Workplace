#coding:utf-8
__author__ = 'narglc'

import re

#中文正则表达式测试
# html = '''
#             var SHARINGINFO = {
#                 title: '【赛里木湖【胶片 】】我们把西瓜放在湖里冰镇，但这不是我们的车子也不是我们的西瓜',
#                 url: 'http://www.douban.com/photos/photo/1707014033/',
#                 pic: 'http://img3.douban.com/view/photo/photo/public/p1707014033.jpg',
#                 desc: '我们把西瓜放在湖里冰镇，但这不是我们的车子也不是我们的西瓜'
#             };
#         '''
# temp = html.decode('utf8')
# pattern = re.compile(u"[\u4e00-\u9fa5]{1,100}")    #此处的{1,100}指讲100个汉字作为一组输出
# results =  pattern.findall(temp)
# print results
# for i in results:
#     print i
#
# print u'\u4e2d\u4f20\u8bf4\u4e2d\u7684\u8d85\u7ea7\u80fd\u91cf\u6587'.encode('utf-8')


context=open('2.shtml')
cont=context.read()

#方案一
# temp = cont.decode('utf8')
# pattern = re.compile(u"[\u4e00-\u9fa5]{1,100}")    #此处的{1,100}指讲100个汉字作为一组输出
# results =  pattern.findall(temp)
# print results
# for i in results:
#     print i

#方案二
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
print "---------------------------------------------------------------------------"
print "正文部分（通用版本）:"
Text = re.findall(r'<div class="article-summary articletext" >(.+?)</div>', cont,re.S)
# text = re.findall(r'>(.*?)<',Text)
for k in Text:
    print k
context.close()

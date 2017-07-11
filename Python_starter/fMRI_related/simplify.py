#!/usr/bin/python
#coding:utf-8

#ver3.0
#Author:Narglc
#Data:2017.2.23
#try to change the main code to a function
#自主命名输出文件名，但格式为.csv格式
#即,使用逗号或tab分割有效信息

def simplify(filename,resultfile):
	con = open(filename,'r')
	out = open(resultfile,'a')
	AAL='narglc'
	while True:
		line=con.readline()
		line = line.strip('\n')    #删除str末尾的\n换行符
		if line:
			if 'byScans' in line:
				SubNo=line[-22:-16]
				out.write('\n\nResult of '+SubNo+'\n')           #被试信息
			if 'Number of clusters' in line:
				 splitLine=line.split(': ')
				 numOfClusters=splitLine[1]      #总共多少个Cluster
				 out.write('Clusters:'+numOfClusters+'\n')
				 out.write('Voxels,coordinate,anatomy,AAL\n')
			elif 'Number of voxels' in line:
				splitLine=line.split(': ')
				numOfVoxels=splitLine[1]         #对应的cluster总共有多少voxels
				out.write(numOfVoxels+',')
			elif 'region' in line:
				splitLine=line.split(' // ')
				splitLine_tmp=splitLine[6].split(' ')
				AAL=splitLine_tmp[0]
				keep_line=','.join([splitLine[3],AAL])  #峰值点对应脑区
				out.write(keep_line)
				if AAL=='undefined':
					out.write('\n')
			elif 'coordinate:' in line:
				splitLine = line.split(': ')
				coordinate = splitLine[1]        #峰值点对应坐标
				out.write(coordinate+',')
			elif AAL in line and not('Peak' in line) and AAL!='undefined':
				if '\t' in line:
					splitLine = line.split('\t')
					voxels=int(splitLine[0])
				else:
					splitLine = line.split(' ')
					voxels = splitLine[-3]
				out.write('('+str(voxels)+'),\n')
				AAL='narglc'
		else:
			break 
	con.close()
	out.close()

subs=range(10,13)								##针对数据进行修改
resultFile='TestData/out.result'					##输出文件名
for sub in subs:
#	if sub==22:									##确定是否剔除数据
#		continue
	filename='TestData/sub0'+str(sub)+'.data'
	simplify(filename,resultFile)
	print filename[-10:]+' done.'

#filename='TestData/all_fMRI.data'
#simplify(filename,resultFile)
print "Done."

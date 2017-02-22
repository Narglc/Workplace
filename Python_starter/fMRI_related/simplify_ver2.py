#!/usr/bin/python
#coding:utf-8

#ver2.0
#output format: csv
#使用逗号或tab分割有效信息

con = open('fMRI.result','r')
out = open('accurate.csv','a')
out.write('\n\nResult of ')
AAL='narglc'
while True:
    line=con.readline()
    line = line.strip('\n')    #删除str末尾的\n换行符
    if line:
        if 'byScans' in line:
            SubNo=line[-22:-16]
            out.write(SubNo+'\n')           #被试信息
        if 'Number of clusters' in line:
             listline=line.split(': ')
             numOfClusters=listline[1]      #总共多少个Cluster
             out.write('Clusters:'+numOfClusters+'\n')
             out.write('Voxels,coordinate,anatomy,AAL\n')
        elif 'Number of voxels' in line:
            listline=line.split(': ')
            numOfVoxels=listline[1]         #对应的cluster总共有多少voxels
            out.write(numOfVoxels+',')
        elif 'region' in line:
            ll=line.split(' // ')
            keep_line=','.join([ll[3],ll[6]])  #峰值点对应脑区
            AAL=ll[6]
            out.write(str(keep_line))
            if AAL=='undefined':
                out.write('\n')
        elif 'coordinate:' in line:
            listline = line.split(': ')
            coordinate = listline[1]        #峰值点对应坐标
            out.write(coordinate+',')
        elif AAL in line and not('Peak' in line) and AAL!='undefined':
            listline = line.split('\t')
            voxels=int(listline[0])
            out.write('('+str(voxels)+'),\n')
            AAL='narglc'
    else:
        break 
con.close()
out.close()

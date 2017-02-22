#!/usr/bin/python
#coding:utf-8

#ver1.0
#get result format as:
#Newest Result:
#Number of clusters found: 10
#----------------------
#Cluster 1
#Number of voxels: 1369
#Peak MNI coordinate: 24 -90  15
#Peak MNI coordinate region:  // Middle Occipital Gyrus // Occipital_Sup_R (aal)

print "Simplification begin!"
con = open('fMRI.result')
out = open('accurate.result','a')
out.write('\nNewest Result:'+'\n')
while True:
    line=con.readline()
    if line:
        if 'Number' in line or 'coordinate:' in line or  'Cluster' in line or '---------'in line:
            print line
            out.write(line)
        elif 'region' in line:
            ll=line.split('//')
            keep_line='//'.join([ll[0],ll[3],ll[6]])   ##or ll[-1]
            print keep_line
            out.write(str(keep_line))
    else:
        break

con.close()
out.close()

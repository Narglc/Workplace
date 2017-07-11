#!/bin/sh
a=2
echo $0 $1 $2
echo "参数个数为："$#
for var in $@; do
	echo $var;
done
echo "Above is FOR..."
echo "==============="

if [ $1 = 2 ]; then
	echo "I did it.";
else
	echo "Fail!!";
fi
if [ -e ReadMe.md ]; then
	echo "exist the 'ReadMe.md'";
else
	echo "No this file.";
fi
echo "while ex:"
num=6
while [ $num -gt 0 ];do
	echo ${num}_has_done...;
	num=`echo "$num-1"|bc -l`;
done
echo "function:"
hi(){ echo "Hi,$1"; }
hi
hi There
Tea() { echo `ls`; }
Tea

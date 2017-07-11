#!/bin/bash

array=(A b "Narglc" 132)
echo '第三个元素为'${array[2]}
echo "最后一个元素为"${array[3]}
echo ${array[@]}

echo 长度
length=${#array[*]}
echo $length

echo ${#array[2]}

#coding:utf-8

# 一刷
def first_just_input_and_print():
    x = input("pls input a num:")
    print("x+78="+str(x))
    y +=x
    print(y)
    string = input("pls input a str:")
    print("str:",end=" ")
    print(string)

# 二刷
def transform_to_bool():
    x = 0
    y = 328
    print("0->",bool(x),"\t328->",bool(y))
    str1 = "abc"
    str2 = ""
    print("abc->",bool(str1),"\t->",bool(str2))
    print("None->",bool(None),"\t{}->",bool({}),"\t[]->",bool([]),"\t()->",bool(()))
    print("计算式:")
    print("23+34->",bool(23+34),"\t34-34->",bool(34-34))

# 三刷
def deal_score_from_one_line(string):
    string_list = string.split(" ")
    name = string_list[0]
    score_list = string_list[1:]
    sum = 0
    for each_score in score_list:
        sum += int(each_score)
    return name + " " + str(sum) + "\n"

def read_score_from_file_and_calculate_them():
    with open("report.txt") as f_obj:
        for line in f_obj.readlines():
            with open("output.log",'a') as output_obj:
                output_obj.write(deal_score_from_one_line(line))

if __name__ == '__main__':
    print("-------result-------")
    #first_just_input_and_print()
    transform_to_bool()
    read_score_from_file_and_calculate_them()
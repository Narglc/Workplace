# #coding:utf-8
# VOWELS = "AEIOUY"
# CONSONANTS = "BCDFGHJKLMNPQRSTVWXZ"
# #biaodian=[' ',',','...']
# alphabets="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
#
# def checkio(text):
#     out=""
#     for i in text:                          #规格化字符串text
#         #if i=="," or i=="." or i=="?":
#         if not (i in alphabets):
#             out+=" "
#         else:
#             out+=i
#     text=out.upper().split(" ")
#     num=0
#     for i in text:                          #删除text中的非单词字符串
#         if not (i.isalpha()):
#             text.remove(i)
#         elif len(i)==1:
#             text.remove(i)
#     for i in text:                          #将每个单词的奇偶位分开到两个列表中
#         single=[]
#         double=[]
#         for j in range(len(i)):
#             if j%2==1:
#                 single.append(i[j])
#             else:
#                 double.append(i[j])
#         vnum,cnum=0,0                          #标记single
#         s_state=""
#         for x in single:
#             if x in VOWELS:
#                 vnum+=1
#             if x in CONSONANTS:
#                 cnum+=1
#         if vnum==len(single):
#             s_state="VOW"
#         elif cnum==len(single):
#             s_state="CON"
#         vnum,cnum=0,0                           #标记double
#         d_state=""
#         for x in double:
#             if x in VOWELS:
#                 vnum+=1
#             if x in CONSONANTS:
#                 cnum+=1
#         if vnum==len(double):
#             d_state="VOW"
#         elif cnum==len(double):
#             d_state="CON"
#         if (s_state=="VOW" and d_state=="CON") or (d_state=="VOW" and s_state=="CON"):         #判断每个字符串是否符合条纹单词要求
#             num+=1
#     return num
#
#
# #These "asserts" using only for self-checking and not necessary for auto-testing
# if __name__ == '__main__':
#     assert checkio(u"My name is ...") == 3, "All words are striped"
#     assert checkio(u"Hello world") == 0, "No one"
#     assert checkio(u"A quantity of striped words.") == 1, "Only of"
#     assert checkio(u"Dog,cat,mouse,bird.Human.") == 3, "Dog, cat and human"
#     print checkio(u"My name is ...")
#     print checkio


'''#    未解决
def min(*args, **kwargs):
    key = kwargs.get("key", None)
    result=args[0]
    for i in args:
        if key==None:
            if i<result:
                result=i
        if key=="key":
            if key(i)<key(result):
                result=i
    return result
def max(*args, **kwargs):
    key = kwargs.get("key", None)
    return None
if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    # assert max(3, 2) == 3, "Simple case max"
    # assert min(3, 2) == 2, "Simple case min"
    # assert max([1, 2, 0, 3, 4]) == 4, "From a list"
    # assert min("hello") == "e", "From string"
    # assert max(2.2, 5.6, 5.9, key=int) == 5.6, "Two maximal items"
    # assert min([[1, 2], [3, 4], [9, 0]], key=lambda x: x[1]) == [9, 0], "lambda key"
    print max(3, 2)
'''


#
# def checkio(opacity):
#     Fab=[1,2]
#     for i in range(2,19):
#         Fab.append(Fab[i-1]+Fab[i-2])
#     # print Fab
#     age=10000
#     age_list=[]
#     for j in range(5000):
#         if j in Fab:
#             age=age-j
#         elif j!=0:
#             age+=1
#         age_list.append(age)
#     # print age_list
#     # print len(age_list)
#     # age_list=age_list[0:5000]
#     return age_list.index(opacity)
#
#
#
# #These "asserts" using only for self-checking and not necessary for auto-testing
# if __name__ == '__main__':
#     assert checkio(10000) == 0, "Newborn"
#     assert checkio(9999) == 1, "1 year"
#     assert checkio(9997) == 2, "2 years"
#     assert checkio(9994) == 3, "3 years"
#     assert checkio(9995) == 4, "4 years"
#     assert checkio(9990) == 5, "5 years"
# # print checkio(10000)




# def check_connection(network, first, second):
#     brotherhood=[first]
#     count=0
#     while 1:
#         for i in network:
#             for k in brotherhood:
#                 if k in i:
#                     two_points=i.split("-")
#                     for j in two_points:
#                         if  not (j in brotherhood):
#                             brotherhood.append(j)
#         count+=1
#         # print brotherhood
#         if count>len(network):
#             break
#     if second in brotherhood:
#         return True
#     else:
#         return False
#
# if __name__ == '__main__':
#     #These "asserts" using only for self-checking and not necessary for auto-testing
#     assert check_connection(
#         ("dr101-mr99", "mr99-out00", "dr101-out00", "scout1-scout2",
#          "scout3-scout1", "scout1-scout4", "scout4-sscout", "sscout-super"),
#         "scout2", "scout3") == True, "Scout Brotherhood"
#     assert check_connection(
#         ("dr101-mr99", "mr99-out00", "dr101-out00", "scout1-scout2",
#          "scout3-scout1", "scout1-scout4", "scout4-sscout", "sscout-super"),
#         "super", "scout2") == True, "Super Scout"
#     assert check_connection(
#         ("dr101-mr99", "mr99-out00", "dr101-out00", "scout1-scout2",
#          "scout3-scout1", "scout1-scout4", "scout4-sscout", "sscout-super"),
#         "dr101", "sscout") == False, "I don't know any scouts."



# def letter_queue(commands):
#     result=""
#     if len(commands)==0:
#         pass
#     else:
#         for i in commands:
#             if " " in i:
#                 [command,data]=i.split(" ")
#             else:
#                 command=i
#             if command=="PUSH":
#                 result+=data
#             if command=="POP":
#                 if len(result)!=0:
#                     result=result[1:]
#                 else:
#                     result=""
#     return result
#
# if __name__ == '__main__':
#     #These "asserts" using only for self-checking and not necessary for auto-testing
#     assert letter_queue(["PUSH A", "POP", "POP", "PUSH Z", "PUSH D", "PUSH O", "POP", "PUSH T"]) == "DOT", "dot example"
#     assert letter_queue(["POP", "POP"]) == "", "Pop, Pop, empty"
#     assert letter_queue(["PUSH H", "PUSH I"]) == "HI", "Hi!"
#     assert letter_queue([]) == "", "Nothing"
#     print letter_queue(["PUSH A", "POP", "POP", "PUSH Z", "PUSH D", "PUSH O", "POP", "PUSH T"])




# alphabet="abcdefghijklmnopqrstuvwxyz"
# def count(first,second):
#     sum=0
#     first=first.lower()
#     second=second.lower()
#     if first[0]==second[0]:
#         sum+=10
#     if first[-1]==second[-1]:
#         sum+=10
#     if len(first)<=len(second):
#         sum+=(len(first)*1.0/len(second))*30
#     else:
#         sum+=(len(second)*1.0/len(first))*30
#     unique,common="",""
#     for i in first:
#         if i in second:
#             if not (i in common):
#                 common+=i
#         if not (i in unique):
#             unique+=i
#     for j in second:
#         if not (j in unique):
#             unique+=j
#     sum+=(len(common)*1.0/len(unique))*50
#     return sum
#
# def find_word(message):
#     new_list=""
#     for i in message.lower():
#         if i in alphabet:
#             new_list+=i
#         else:
#             new_list+=" "
#     new_list=new_list.split(" ")
#     context=[]
#     for j in new_list:
#         if len(j)!=0:
#             context.append(j)
#     new_list=context
#     lenght=len(new_list)
#     print new_list
#     sum_list=[]
#     for x in new_list:
#         sum=0
#         for y in new_list:
#             sum+=count(x,y)
#         sum_list.append(sum-100)
#     maxs=sum_list[0]
#     bit,resultbit=0,0
#     for s in sum_list:
#         if s>=maxs:
#             maxs=s
#             resultbit=bit
#         bit+=1
#     return new_list[resultbit]
#
# if __name__ == '__main__':
#     #These "asserts" using only for self-checking and not necessary for auto-testing
#     # assert find_word(u"Speak friend and enter.") == "friend", "Friend"
#     # assert find_word(u"Beard and Bread") == "bread", "Bread is Beard"
#     # assert find_word(u"The Doors of Durin, Lord of Moria. Speak friend and enter. "
#     #                  u"I Narvi made them. Celebrimbor of Hollin drew these signs") == "durin", "Durin"
#     # assert find_word(u"Aoccdrnig to a rscheearch at Cmabrigde Uinervtisy."
#     #                  u" According to a researcher at Cambridge University.") == "according", "Research"
#     # assert find_word(u"One, two, two, three, three, three.") == "three", "Repeating"
#     print find_word(u"Fantasy is escapist, and that is its glory. If a soldier is imprisioned by the enemy, don't we consider it his duty to escape?. If we value the freedom of mind and soul, if we're partisans of liberty, then it's our plain duty to escape, and to take as many people with us as we can!")
#




# def checkio(matrix):
#     #replace this for solution
#     row_lines=len(matrix)
#     col_lines=len(matrix[0])
#     for i in matrix:
#         for j in range(col_lines-3):
#             if i[j]==i[j+1]==i[j+2]==i[j+3]:
#                 print "Horizontal"
#                 return True
#     for col in range(col_lines):
#         for row in range(row_lines-3):
#             if matrix[row][col]==matrix[row+1][col]==matrix[row+2][col]==matrix[row+3][col]:
#                 print "Vertical"
#                 return True
#     for x in range(0,row_lines-3):
#         for y in range(3,col_lines):
#             if matrix[x][y]==matrix[x+1][y-1]==matrix[x+2][y-2]==matrix[x+3][y-3]:
#                 print "Diagonal:/"
#                 return True
#     for r in range(0,row_lines-3):
#         for s in range(0,col_lines-3):
#             if matrix[r][s]==matrix[r+1][s+1]==matrix[r+2][s+2]==matrix[r+3][s+3]:
#                 print "Diagonal:\\"
#                 return True
#     print "Nothing Here"
#     return False
#
# if __name__ == '__main__':
#     #These "asserts" using only for self-checking and not necessary for auto-testing
#     assert checkio([
#         [1, 2, 1, 1],
#         [1, 1, 4, 1],
#         [1, 3, 1, 6],
#         [1, 7, 2, 5]
#     ]) == True, "Vertical"
#     assert checkio([
#         [7, 1, 4, 1],
#         [1, 2, 5, 2],
#         [3, 4, 1, 3],
#         [1, 1, 8, 1]
#     ]) == False, "Nothing here"
#     assert checkio([
#         [2, 1, 1, 6, 1],
#         [1, 3, 2, 1, 1],
#         [4, 1, 1, 3, 1],
#         [5, 5, 5, 5, 5],
#         [1, 1, 3, 1, 1]
#     ]) == True, "Long Horizontal"
#     assert checkio([
#         [7, 1, 1, 8, 1, 1],
#         [1, 1, 7, 3, 1, 5],
#         [2, 3, 1, 2, 5, 1],
#         [1, 1, 1, 5, 1, 4],
#         [4, 6, 5, 1, 3, 1],
#         [1, 1, 9, 1, 2, 1]
#     ]) == True, "Diagonal"



# def checkio(data):
#
#     #replace this for solution
#     return ""
#
# #These "asserts" using only for self-checking and not necessary for auto-testing
# if __name__ == '__main__':
#     assert checkio(u"(2,2),(6,2),(2,6)") == "(x-4)^2+(y-4)^2=2.83^2"
#     assert checkio(u"(3,7),(6,9),(9,7)") == "(x-6)^2+(y-5.75)^2=3.25^2"





'''未解决'''
# def safe_pawns(pawns):
#     new_order=[]
#     for j in range(1,9):
#         print j
#         for i in pawns:
#             if i[1]==j:
#                 print "into"
#                 print i[1]
#                 new_order.append(i)
#     print new_order
#
#     return 0
# if __name__ == '__main__':
#     #These "asserts" using only for self-checking and not necessary for auto-testing
#     # assert safe_pawns({"b4", "d4", "f4", "c3", "e3", "g5", "d2"}) == 6
#     # assert safe_pawns({"b4", "c4", "d4", "e4", "f4", "g4", "e5"}) == 1
#     print safe_pawns({"b4", "d4", "f4", "c3", "e3", "g5", "d2"})




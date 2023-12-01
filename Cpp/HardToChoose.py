import random

NumOptions=int(input("请输入您选项的个数："))
options=[]
probability=[]
for i in range(NumOptions):
    options.append(input("\n您的第{}个选项是：".format(i+1)))
    if (i==NumOptions-1):
        tmp_sum=sum(probability)
        print("OK，那么最后一个选项的概率就是%.2f"%(100-tmp_sum),"%")
        probability.append(100-tmp_sum)
        break
    probability.append(float(input("您希望在这个选项中的概率是多少（单位为%）：")))

print("\n您现在的设定的选项及概率分别是：\n")
for i in range(NumOptions):
    print("{}:\t {:.5}%".format(options[i],probability[i]))

tmp=0
for i in range(NumOptions):
    probability[i]=tmp+probability[i]
    tmp=probability[i]

input("\n上天为您的选择将在您摁下回车键后显示出来：\n")
choose=random.random()*100
# print(choose)
for i in range(NumOptions):
    if(choose<=probability[i]):
        print("当然是选择“",options[i],"”啦")
        break
input()
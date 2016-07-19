import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String name = "爱慕课";
        char sex = '男';
        int num = 18;
        double price = 120.5;
        boolean isOK = true;
        System.out.println(name);
        System.out.println(sex);
        System.out.println(num);
        System.out.println(price);
        System.out.println(isOK);

        //强制类型转换
        System.out.println("强制类型转换");
        double heightAvg1 = 176.2;
        int heightAvg2 = (int) heightAvg1;
        System.out.println(heightAvg1);
        System.out.println(heightAvg2);

        //常量类型
        final String SEX1 = "男";
        final String Sex = "女";
        System.out.println(SEX1);
        System.out.println(Sex);

        //运算符号操作
        int age1 = 24;
        int age2 = 18;
        int age3 = 36;
        int age4 = 27;
        int sum = age1 + age2 + age3 + age4;
        double avg = sum / 4;
        int minus = age1 - age2;
        int newAge = --age1;

        System.out.println("年龄总和：" + sum);
        System.out.println("平均年龄：" + avg);
        System.out.println("年龄差值：" + minus);
        System.out.println("自减后的年龄：" + newAge);


        //字符串char用单引号，为何不能用双引号？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
        char today = '日';
        switch (today) {
            case '一':
            case '三':
            case '五':
                System.out.println("早餐吃包子");
                break;
            case '二':
            case '四':
            case '六':
                System.out.println("早餐吃油条");
                break;
            case '日':

                System.out.println("吃主席套餐");
        }

        System.out.println("New Start!!!");


        //switch case 语句
        char today1 = '日';
        switch (today1) {
            case '一':
            case '三':
            case '五':
                System.out.println("早餐吃包子");
                break;
            case '二':
            case '四':
            case '六':
                System.out.println("早餐吃油条");
                break;
            default:
                System.out.println("吃主席套餐");
                break;
        }
        int i = 1;
        while (i < 6) {
            System.out.println(i);
            ++i;
        }


        int sum1 = 0; // 保存 1-50 之间偶数的和
        int num1 = 2; // 代表 1-50 之间的偶数
        do {
            //实现累加求和
            sum1 += num1;
            num1 = num1 + 2; // 每执行一次将数值加2，以进行下次循环条件判断
        } while (num1 <= 50); // 满足数值在 1-50 之间时重复执行循环
        System.out.println(" 50以内的偶数之和为：" + sum1);


        //break
        int x = 1;
        int sum3 = 0;
        while (x>=1) {
            sum3 += x;
            if (sum3 > 20) {
                System.out.println("当前的累加值为：" + sum3);
                break;
            }
        }

        //打印长方形
        for(i=1;i<=3;i++){
            for(int j=1;j<9;j++){
                System.out.print("*");
            }
            System.out.println();
        }

        //判断一个输（小于10位）的位数。
        num = 199;
        int count = 0;
        while (num>=10){
            num=num/10;
            count++;
        }
        count+=1;
        System.out.println("它是个"+count+"位的数！");

        //为指定成绩加分，直到分数大于等于 60 为止，输出加分前和加分后的成绩，并统计加分的次数
        Scanner input = new Scanner(System.in);
        System.out.println("请输入考试成绩：");
        int score=input.nextInt();//获取用户输入成绩并保存在变量中
        // 变量保存成绩
        //int score = 53;
        // 变量保存加分次数
        count = 0;
        //打印输出加分前成绩
        System.out.print("加分前成绩："+score);
        // 只要成绩小于60，就循环执行加分操作，并统计加分次数
        while(score<=60){
            score++;
            count++;
        }
        //打印输出加分后成绩，以及加分次数
        System.out.println("加分后成绩："+score);
        System.out.println("共加了"+count+"次！");



    }
}
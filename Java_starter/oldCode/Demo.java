package com.stupid.demo;
/**
 * Created by narglc on 7/7/16.
 */
//导入Scanner类
import java.util.Scanner;

//导入Arrays类
import java.util.Arrays;


public class Demo {
    public static void main(String[] args) {
        /**
        int classNum=3;
        int stuNum=4;
        double sum=0;
        double avg=0;
        Scanner input=new Scanner(System.in);//创建Scanner对象
        for(int i=1;i<=classNum;i++){
            System.out.println("×××请输入第"+i+"个班级的成绩×××");
            for(int j=1;j<=stuNum;j++){
                System.out.print("请输入第"+j+"个学员的成绩：");
                int score=input.nextInt();      //获取输入的成绩
                sum+=score;
            }
            avg=sum/stuNum;
            System.out.println("第"+i+"个班级的成绩为："+avg);
            sum=0;
        }
         **/
        int[] scores = new int[2];
        scores[0]=99;
        scores[1]=56;

        // 定义一个长度为5的字符串数组，保存考试科目信息
        String[] subjects = new String[5];
        // 分别为数组中的元素赋值
        subjects[0] = "Oracle";
        subjects[1] = "PHP";
        subjects[2] = "Linux";
        subjects[3] = "Java";
        subjects[4] = "HTML";
        System.out.println("数组中第4个科目为：" + subjects[3]);

        int[] grade={67,78,98,67};
        //等价于
        int[] grades=new int[]{67,87,56,98};

        // 定义一个长度为 3 的字符串数组，并赋值初始值
        String[] hobbys = { "sports", "game", "movie" };
        System.out.println("循环输出数组中元素的值：");
        // 使用循环遍历数组中的元素
        for(int i=0;i<hobbys.length;i++){
            System.out.println(hobbys[i]);
        }

        //Coding Practice
        // 定义一个整型数组，并赋初值
        int[] nums = new int[] { 61, 23, 4, 74, 13, 148, 20 };

        int max = nums[0]; // 假定最大值为数组中的第一个元素
        int min = nums[0]; // 假定最小值为数组中的第一个元素
        double sum = 0;// 累加值
        double avg = 0;// 平均值

        for (int i = 0; i < nums.length; i++) { // 循环遍历数组中的元素
            // 如果当前值大于max，则替换max的值
            if(nums[i]>max)
                max=nums[i];
            // 如果当前值小于min，则替换min的值
            if(nums[i]<min)
                min=nums[i];
            // 累加求和
            sum+=nums[i];
        }
        // 求平均值
        avg=sum/nums.length;

        System.out.println("数组中的最大值：" + max);
        System.out.println("数组中的最小值：" + min);
        System.out.println("数组中的平均值：" + avg);

        // 定义一个字符串数组
        String[] hobbys2 = { "sports", "game", "movie" };

        // 使用Arrays类的sort()方法对数组进行排序
        Arrays.sort(hobbys2);

        // 使用Arrays类的toString()方法将数组转换为字符串并输出
        System.out.println(Arrays.toString(hobbys2));
        // / 使用foreach遍历输出数组中的元素                                    foreach""
        for (String hobby:hobbys2) {
            System.out.println(hobby);
        }

    }
}

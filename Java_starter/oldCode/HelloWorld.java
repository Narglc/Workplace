package com.stupid.demo;

/**
 * Created by narglc on 7/12/16.
 */
public class HelloWorld {
    static String className = "JAVA开发一班";
    //完成 main 方法
    public static void main(String[] args) {
        System.out.println(HelloWorld.className);
        HelloWorld hello = new HelloWorld();
        int[] scores={89,-23,64,91,119,52,73};
        hello.Sort(scores);

    }

    //定义方法完成成绩排序并输出前三名的功能
    public void Sort(int[] scores){
        int j=0;
        //判断成绩有效性
        for(int i=0;i<scores.length;i++){
            if(scores[i]>0 & scores[i]<100){
                j++;
            }
        }

        int[] newScores = new int[j];
        j=0;
        for(int i=0;i<scores.length;i++){
            if(scores[i]>0 && scores[i]<100){
                newScores[j]=scores[i];
                j++;
            }
        }


        for(j=0;j<newScores.length;j++){
            System.out.println(newScores[j]);
        }

        //成绩排名并输出
        int tmp=0;
        for(int i=0;i<(newScores.length-1);i++){
            for(j=i+1;j<newScores.length;j++){
                if(newScores[i]<newScores[j]){
                    tmp=newScores[i];
                    newScores[i]=newScores[j];
                    newScores[j]=tmp;
                }
            }
        }

        System.out.println("考试成绩的前三名为：");
        for(j=0;j<3;j++){
            System.out.println(newScores[j]);
        }

    }
}

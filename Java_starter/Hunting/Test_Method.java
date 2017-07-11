package cn.exercises;

import java.util.Arrays;
/**
 * 小伙伴们，请根据所学知识，编写一个 JAVA 程序，实现输出考试成绩的前三名
 * @author Narglc
 *要求：
 *1、 考试成绩已保存在数组 scores 中，数组元素依次为 89 , -23 , 64 , 91 , 119 , 52 , 73
 *2、 要求通过自定义方法来实现成绩排名并输出操作，将成绩数组作为参数传入
 *3、 要求判断成绩的有效性（ 0—100 ），如果成绩无效，则忽略此成绩
 */
public class Test_Method {
	public int[] mySort(int[] array){
		int[] newArr=new int[array.length];
		for (int i = 0,j=0; i < array.length; i++) {
			if (array[i]>=0 && array[i]<=100) {
				newArr[j++]=array[i];
			}
		}
		int tmp;
		for (int j2 = 0; j2 < newArr.length-1; j2++) {
			for (int k = j2+1; k < newArr.length; k++) {
				if (newArr[k]>newArr[j2]) {
					tmp=newArr[j2];
					newArr[j2]=newArr[k];
					newArr[k]=tmp;
				}
			}
		}
		return newArr;
	}
	
	
	public static void main(String[] args) {
		int[] scores={89,-23,64,91,119,52,73};
		Test_Method test=new Test_Method();
		int[] rank=test.mySort(scores);
		System.out.println(Arrays.toString(rank));
		System.out.println("考试成绩的前三名为:");
		System.out.println(rank[0]);
		System.out.println(rank[1]);
		System.out.println(rank[2]);
		
//		Test_Method test=new Test_Method();
//		Arrays.sort(scores);
//		System.out.println(Arrays.toString(scores));
//		System.out.println("����"+scores.length+"���ɼ���Ϣ��");
	
//		System.out.println((int)(Math.random()*100));

	}

}

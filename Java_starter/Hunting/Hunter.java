package cn.exercises;
import java.util.Arrays;

public class Hunter {
	//无参无返回值
	public void show() {
		System.out.println("测试方法的定义！");
	}
	
	//无参带返回值
	public int returnNum() {
		int b=23;
		return b;
	}
	//带参带返回值
	public String addString(String str1,String str2) {
		String str3=str1+str2;
		return str3;
	}
	//带参无返回值
	
	public static void main(String[] args) {
		//方法的定义与调用！！！
		System.out.println("四类方法的调用测试:");
		Hunter test=new Hunter();
		test.show();
		System.out.println(test.returnNum());
		System.out.println(test.addString("narglc，", "干巴爹！"));
		
		System.out.println("===========");
		// TODO Auto-generated method stub
		int score1=97;
		char score2=(char)score1;
		System.out.println(score2);
		
		double num=97.3;
		int num2=(int)num;
		System.out.println(num2);
		
		//常量,一旦被赋值，变不允许改变，常量名 一般使用 大写字符
		final double PI=3.141592653580703238462643;
		System.out.println(PI);
		
		/** 文档注释以/**开头
		 *  多行注释以/*开头
		 *  单行注释以//开头
		 */
		System.out.println("num2:"+num2);
		System.out.println("取余数"+num2%2);    //  % 用于取余数
		
		int No=1;
		switch (No) {
		case 1:
		case 2:
			System.out.print("IPAD");
//			break;
		case 3:
			System.out.println("移动电源");
			break;
		default:	// default 可以出现在任何位置，也可以省略
			System.out.println("flash disk");
		}
		
		//三种循环
		while (No<6) {
			System.out.println(No+". 通知尚需努力");
			No++;
		}
		System.out.println("current No:"+No);
		
		do{
			System.out.println(No+"革命尚未成功！");
			No++;
		}while(No<12);
		
		for (int i = 0, j=5; i < 6; i++,j--) {
			System.out.println(i+"+"+j+"="+(i+j));
		}
		
		for(;;){  						//三个表达式都可以省略，但“;”不可省
			if(No==18){
				break;
			}
			System.out.println("No:===>"+No++);
		}
		
		//数组  以下为两种  声明方式
		int[] arr={23,54,5,78};
		char xarr[]={'a','f','c','d'};
		int[] scores=new int[8];
//		scores={1,2,3,5,6,7};
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i]);
			System.out.println(xarr[i]);
			scores[i]=arr[i];
			scores[7-i]=arr[i];
		}
		
		System.out.println(Arrays.toString(scores));
		Arrays.sort(scores);
		System.out.println(Arrays.toString(scores));
		System.out.println("=====");
		
		//使用foreach操作数组，foreach为for的一种简写
		String[] nar={"Nar","glc","li","ke","Mo","mo"};
		for (String i : nar) {
			System.out.println(i);
		}
		
		//二维数组
		int[][] _2Array={{1,2},{4,5},{7,8}};
		for (int i = 0; i < _2Array.length; i++) {
			for (int j = 0; j < _2Array[1].length; j++) {
				System.out.print(_2Array[i][j]+"  ");
			}
			System.out.println();
		}
		System.out.println("使用foreach遍历");
		for (int[] is : _2Array) {
			for (int i : is) {
				System.out.print(i+"  ");
			}
			System.out.println();
		}
		System.out.println(Arrays.toString(_2Array[0]));
		
	}

}

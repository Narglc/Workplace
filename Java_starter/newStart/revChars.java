//定义一个函数接受一个char类型的数组对象，然后翻转数组中的元素。
//使用冒泡排序算法即可解决该问题。
import java.util.*;
class Demo3{
	public static void main(String[] args){
		char[] arr={'a','b','c','d','e'};
		revChars(arr);
		String info=Arrays.toString(arr);
		System.out.println("arr为："+info);
		Arrays.sort(arr);		
		String info2=Arrays.toString(arr);
		System.out.println("排序后的arr为："+info2);
//		revChars(arr);
		System.out.println("===============");
		for(int i=0;i<arr.length;i++){
			System.out.print(arr[i]);
		}
	}
	public static void revChars(char[] arr){
		for(int i=1;i<arr.length-1;i++){
			for(int j=0;j<arr.length-i;j++){
				if(arr[j]<arr[j+1]){
					char tmp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=tmp;
				}
			}
		}
	}
}


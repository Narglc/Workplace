//编写一个函数，删除数组中的0，并返回
import java.util.*;
class Demo{
	public static int[] deleteZero(int[] arr){
		int len=0;
		for(int i=0;i<arr.length;i++){
			if(arr[i]!=0){
				len++;
			}
		}
		int[] newArr=new int[len];
		len=0;
		for(int i=0;i<arr.length;i++){
			if(arr[i]!=0){
				newArr[len++]=arr[i];		;
			}
		}
		return newArr;
	}

	public static void main(String[] args){
		int[] arr={0,0,12,1,0,4,6,0};
		System.out.println(Arrays.toString(deleteZero(arr)));
	}
}

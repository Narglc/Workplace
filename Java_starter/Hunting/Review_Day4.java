import java.util.Arrays;
/**
 * 小练习
 * @author Narglc
 * 需求：定义一个函数接收一个数组对象和一个要查找的目标元素，函数要返回该目标元素在
 * 数组中的索引值，如果目标元素不存在数组中，那么返回-1表示。
 */
public class Review_Day4 {
	public static int getTarget(int[] arr,int target) {
//		Arrays.sort(arr);
//		System.out.println("排序后数组为:"+Arrays.toString(arr));
		int i=0;
		for (;arr[i]!=target;) {
			if (i==arr.length-1) {
				return -1;
			}else {
				i+=1;
			}
		}
		return i;
	}
	
	
	public static void main(String[] args) {
		int[] arr={21,12,44,26,7,39,0};
		System.out.println("原始数组为:"+Arrays.toString(arr));
		//Arrays.bi
		int target=440;
		System.out.println("target的索引值为:"+getTarget(arr,target));
	}
}

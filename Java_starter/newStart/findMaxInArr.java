//使用函数和数组实现寻找数组中的最大值的功能
//两种排序算法：选择排序算法、冒泡排序算法。
class Demo{
	public static void main(String[] args){
		int[] arr={23,3,45,56,34,55};
		System.out.println(getMax(arr));
		System.out.println("45的索引值为"+getIndex(arr,145));
		//arr=bubbleSort(arr);
		bubble2(arr);
		for(int k=0;k<arr.length;k++){
			System.out.print(arr[k]+",");
		}
	}

	//寻找目标元素在数组中的索引值并返回，若不存在则返回-1
	public static int getIndex(int[] arr,int num){
		int index=-1;
		for(int i=0;i<arr.length;i++){
			if(arr[i]==num){
				index=i;
			}
		}
		return index;
	}

	//寻找数组中的最大值的函数
	public static int getMax(int[] arr){
		int max=arr[0];
		for(int i=0;i<arr.length;i++){
			if(max<arr[i]){
				max=arr[i];
			}
		}
		return max;
	}

	//选择排序算法函数
	public static int[] bubbleSort(int[] arr){
		int tmp;
		for(int i=0;i<arr.length-1;i++){
			for(int j=i+1;j<arr.length;j++){
				if(arr[i]<arr[j]){
					tmp=arr[i];
					arr[i]=arr[j];
					arr[j]=tmp;
				}
			}
		}
		return arr;
	}
	//冒泡排序算法函数：把最大值放在最后边
	public static void bubble2(int[] arr){
		for(int i=1;i<arr.length-1;i++){
			for(int j=0;j<arr.length-i;j++){
				if(arr[j]>arr[j+1]){
					int tmp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=tmp;
				}
			}
		}
	}
}

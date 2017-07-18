//about array and function
class Demo6{
	public static void main(String[] args){
		System.out.println("Just remember the syntax of java.");
		int[] arr1=new int[2];
		int[] arr2=new int[2];
		arr1[0]=66;
		arr1[1]=10;
		for(int index=0;index<arr1.length;index++){      //此处有一个数组的属性length
			System.out.print("output the arr1["+index+"]:");
			System.out.println(arr1[index]);	
		}
		arr2[1]=20;
		System.out.println("arr1[1]:"+arr1[1]);
	} 
}

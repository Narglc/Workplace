class myString{
	public static void main(String[] args){
		String str="    Hello     World      ";
		System.out.println("trim后的字符串为："+nar_trim(str));
		str="D:\\20120512\\day123\\myString1.java";
		System.out.println("文件名为:"+getFileName(str));
		str="Nar司机翻车了！";
		System.out.println("反转后为："+reverStr(str));
	}

	public static String reverStr(String str){
		char[] arr=str.toCharArray();
		char[] newArr=new char[arr.length];
		int i=0;
		for(int j=arr.length-1;j>=0;j--){
			newArr[i++]=arr[j];
		}
		str=new String(newArr);
		return str;

	}

	public static String getFileName(String str){
	//方法一： 涉及到正则表达式规则
//		String[] path=str.split("\\\\");
//		return path[path.length-1];
	//方法二：
		int lastIndex=str.lastIndexOf("\\");
		return str.substring(lastIndex+1);
	}

	public static String nar_trim(String str){
		char[] arr=str.toCharArray();
		int start=0;
		int end=arr.length-1;
		char empty=' ';
		for(int i=0;i<str.length();i++){
			if(arr[i]!=empty){
				start=i;
				break;
			}
		}
		for(int i=str.length()-1;i>0;i--){
			if(arr[i]!=empty){
				end=i;
				break;
			}
		}
		return str.substring(start,end+1);
	}
}

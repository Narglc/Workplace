package cn.exercises;

/**
 * Review_Day2@2017-7-12
 * @author Narglc
 * static 静态成员，可以使用对象调用，也可使用类名调用，推荐  类名调用
 * 静态成员属于整个类，当系统第一次使用该类时，就会为其分配内存空间直到该类被卸载才会进行资源回收
 */
public class Review_day2 {

	static String myName="narglc";
	
	//封装  先private属性变量，在设置setter与getter方法
	private String birthday;//="2017-7-12";
	private char Sex;
	public void setBirthday(String myBirth){
		birthday=myBirth;
	}
	public String getBirthday(){
		return birthday;
	}
	
	public char getSex() {
		return Sex;
	}
	public void setSex(char sex) {
		this.Sex = sex;
	}
	
	public static void main(String[] args) {
		
		Review_day2 nar=new Review_day2();
		System.out.println("通过对象调用:"+nar.myName);
		System.out.println("通过类名调用:"+Review_day2.myName);
		nar.myName="Momo";
		System.out.println("修改对象后调用:"+nar.myName);
		Review_day2.myName="类名Momo";
		System.out.println("修改后类名调用:"+Review_day2.myName);
		
		System.out.println("封装学习:");
		nar.setBirthday("2017-7-12 11:44 AM");
		System.out.println("Narglc's birthday is "+nar.getBirthday()+'.');
		
		//equals 用于判断字符串内容是否相同
		System.out.println("equals使用:");
		String today="周末";
		if (today.equals("周末")) {
			System.out.println("Today is Sunday");
		}else {
			System.out.println("今天不是周末");
		}
		
	}
}


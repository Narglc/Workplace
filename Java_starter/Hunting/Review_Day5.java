class Student{
	static	String name;  
	static	String  country  = "China";	  
	
	public Student(String name){
		this.name = name;
	}
}
class Review_Day5 {
	public static void main(String[] args) 
	{
		Student s1 = new Student("DogBaby");
		Student s2 = new Student("DogLeft");
		
		System.out.println("Name:"+ s1.name);
		System.out.println("Name:"+ s2.name);
		
		System.out.println("args' length:"+args.length);
		for (String i : args) {
			System.out.println(i);
		}
	}
}

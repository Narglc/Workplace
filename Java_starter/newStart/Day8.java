//
class Employee{
	int id;
	String name;
	int age;

	public Employee(int i,String n,int a){
		id=i;
		name=n;
		age=a;
		work();
	}

	public void work(){
		System.out.println(name+"努力的工作...");
	}
}

class Demo{
	public static void main(String[] args){
		Employee e=new Employee(123,"Jacques",27);
		System.out.println("ID:"+e.id+" Name:"+e.name+" Age:"+e.age);
	}
}

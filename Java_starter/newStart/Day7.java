//向对象的编程
class Car{
	String name;
	String color;
	int wheel;

	public void run(){
		if(wheel<4){
			System.out.println("车轮少于4个，需到修车厂修理！！！");
		}else{
			System.out.println(color+name+wheel+"个轮子飞快的跑起来了..... ^_^");
		}
	}
}

class carFactor{
	String name;
	String address;
	String tel;

	public void repair(Car c){
		if(c.wheel>=4){
			System.out.println("车子没有问题！");
		}else{
			c.wheel=4;
			System.out.println("车轮少于4个，已修好");
		}
	}
}

class Demo2{
	public static void main(String[] args){
		Car c=new Car();
		c.name="volvo";
		c.color="red";
		c.wheel=3;
		System.out.println("Name:"+c.name+",Color: "+c.color+",wheel:"+c.wheel+".");
		c.run();
		Car d=new Car();
		d.name="北京现代";
		d.color="白色";
		d.wheel=4;
		for(int i=1;i<36;i++){
			d.run();
		}
		d.wheel--;
		d.run();

		//送修
		carFactor f=new carFactor();
		f.name="红墙汽修厂";
		f.address="一环路东一段";
		f.tel="0755-12345678";
		f.repair(d);
		d.run();
	}
}

/**
 * 小练习
 * @author Narglc
 * 需求：需求： 描述一个图形、圆形、 矩形三个类。不管哪种图形都会具备计算面积与周长的行为，但是每种图形计算的方式不一致而已。
 */

//橡皮接口
interface Eraser{
	public abstract void erase(){};
}

//铅笔
class Pencil{
	String name;
	
	public Pencil(String name){
		this.name=name;
	}
	
	public void write(){
		System.out.println(name+"可以写！！！");
	}
}

//带橡皮的铅笔
class Pencil_Era extends Pencil implements Eraser{
	public Pencil_Era(String name){
		super(name);
	}
	
	public void erase() {
		System.out.println(name+"可以涂改！！！");	
	}
}

abstract class Shape{
	String name;
	
	public Shape(String name){
		this.name=name;
	}
	
	public abstract void getArea();
	public abstract void getRound();
}

class Circle extends Shape{
	public static final double PI=3.1415926;
	double r;
	
	public Circle(String name,double r){
		super(name);
		this.r=r;
	}
	public void getArea(){
		System.out.println(name+"的面积为"+PI*r*r);
	}
	public void getRound(){
		System.out.println(name+"的周长为"+2*PI*r);
	}
	
}

class Square extends Shape{
	double length;
	double width;
	
	public Square(String name,double length,double width){
		super(name);
		this.length=length;
		this.width=width;
	}
	
	public void getArea(){
		System.out.println(name+"的面积为"+length*width);
	}
	public void getRound(){
		System.out.println(name+"周长为"+2*(length+width));
	}
}

class Review_Day6{
	public static void main(String[] args) 
	{
		//抽象类
		Circle c = new Circle("圆形", 4.0);
		c.getArea();
		Square s = new Square("长方形", 3.0, 4.0);
		s.getRound();
		
		//接口
		Pencil_Era pe = new Pencil_Era("带橡皮的铅笔");
		pe.erase();
		pe.write();
		Pencil pencil = new Pencil("黄色铅笔");
		pencil.write();
	}
}

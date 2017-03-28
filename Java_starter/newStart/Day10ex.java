//描述一个图形，圆形，矩形三个类，不管哪种图形都会具有计算面积与周长的行为，
//只不过每种图形计算的方式不一致而已。

abstract class Figure{
	double r;
	final double  pi = 3.14;
	double length;
	double width;
	
	public Figure(double r){
		this.r=r;
	}
	
	public Figure(double length,double width){
		this.length=length;
		this.width=width;
	}
	
	abstract double getArea();
	abstract double getLength();
}

class Circle extends Figure{
	public Circle(double r){
		super(r);
	}

	public double getArea(){
		double area=pi*r*r;
		return area;
	}

	public double getLength(){
		double Length=2*pi*r;
		return Length;
	}
}

class Rectangle extends Figure{
	public Rectangle(double length,double width){
		super(length,width);
	}

	public double getArea(){
		double area=length*width;
		return area;
	}
	
	public double getLength(){
		double Length=2(length+width);
		return Length;
	}
}

class Demo{
	public static void main(String[] args){
		Circle c = new Circle(4.0);
		System.out.println("圆的面积为:"+c.getLength());
		Rectangle R=new Rectangle(4,5);
		System.out.println("长方形的面积为:"+R.getLength());
		
	}
}


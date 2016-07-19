public class Outer{
	private int a=99;
	public class Inner{
		int b=2;
		public void test(){
			System.out.println("访问外部类中的a:"+a);
			System.out.println("访问外部类中的b:"+b);
		}
	}
	
	public static void main(String[] args){
		Outer o=new Outer();
		Inner i=o.new Inner();
		i.test();
	}	
}

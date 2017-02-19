//创建一个计算器类，封装操作数、操作符，并实现+-*/四种运算

class Caculator{
	private int  num1;
	private int  num2;
	private char operation;
	
	public void setNum1(int n1){
		num1=n1;
	}
	
	public void setNum2(int n2){
		num2=n2;
	}
	
	public void setOperation(char oper){
		if(oper=='+'||oper=='-'||oper=='*'||oper=='/'){
			operation=oper;
		}else{
			System.out.println("操作符有误！！");
		}
	}

	public double Caculate(){         //此处使用switch语句更好。
		if(operation=='+'){
			return num1+num2;
		}else if(operation=='-'){
			return num1+num2;
		}else if(operation=='*'){
			return num1*num2;
		}else{
			return num1/num2;
		}
	}
}

class Demo{
	public static void main(String[] args){
		Caculator c=new Caculator();
		c.setNum1(23);
		c.setNum2(45);
		c.setOperation('+');
		double sum=c.Caculate();
		System.out.println(sum);
	}	
}

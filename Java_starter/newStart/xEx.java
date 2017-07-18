class nar_NoEnoughMoney extends Exception{
	public nar_NoEnoughMoney(String message){
		super(message);
	}
}

class Demo7{
	public static void main(String[] args) throws nar_NoEnoughMoney{
		int money=19;
		if(money<10){
			throw new nar_NoEnoughMoney("没有带够钱！！！");
		}
		System.out.println("可以吃上地沟油木桶饭了，好开心！");
	}
}

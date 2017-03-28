class NoEnoughMoney extends Exception{
	public NoEnoughMoney(String message){
		super(message);
	}
}

class Demo{
	public static void main(String[] args) throws NoEnoughMoney{
		int money=19;
		if(money<10){
			throw new NoEnoughMoney("没有带够钱！！！");	
		}
		System.out.println("可以吃上地沟油木桶饭了，好开心！");
	}
}

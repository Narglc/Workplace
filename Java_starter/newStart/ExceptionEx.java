class NoEnoughMoney extends Exception{
	public NoEnoughMoney(String message){
		super(message);
	}
}

class Demo4{
	public static void main(String[] args) throws NoEnoughMoney{
		int money=19;
		eat(money);
	}

	public static void eat(int money) throws NoEnoughMoney{
		if(money<10){
			throw new NoEnoughMoney("没有带够钱！！！");	
		}
		System.out.println("可以吃上地沟油木桶饭了，好开心！");
	}
}

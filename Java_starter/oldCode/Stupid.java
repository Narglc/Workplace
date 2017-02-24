public class Test{
    public static void main(String[] args){
        System.out.println("Nar");
        int score = 36;
        if(score >90){
        	System.out.println("A");
      	System.out.println("Very Good");
        }else if(score>80){
        	System.out.println("Still very good!");
        }else if(score>60){
        	System.out.println("Mid!");
        }else{
        	System.out.println("没有希望了！！");
        }

        // Switch语句
        String option="Python";
        switch(option){
            case "C":
                System.out.println("错误");break;
            case "Python":
                System.out.println("正确");break;
            case "C#":
                System.out.println("错误");break;
            case "Java":
                System.out.println("错误");break; 
            default:
                System.out.println("错误");break;
            }
        
        //循环语句for
        int i;
        for(i=1;i<10;i++){
            System.out.println("春天");
        }

        //循环语句while
        int count=0;
        while(count<5){
            System.out.println("秋天");
            count++;
        }

        //计算1+2+3+4+……+100
        i=1;
        int sum=0;
        while(i<=100){
            sum=sum+i;
            i++;
        }
        System.out.println(sum);

        //计算1-100内，7的倍数的综合
        i=1;
        sum=0;
        while(i<=100){
            if(i%7==0){
                sum+=i;
            }
            i++;
        }
        System.out.println("Total is "+sum);

        i=1;
        sum=0;
        do{
            sum+=i;
            i++;
        }while(i<=100);
        System.out.println("1-100 sum "+sum);
        System.out.println("==================");

        for(int co=1;co<6;co++){
            System.out.println("Hello World!");
        }

        // 打印一个5*5的由*构成的矩形
        for(int x=0;x<5;x++){               //控制行数
            for(int y=0;y<5;y++){           //控制列数
                System.out.print("*");
            }
            System.out.println();           //换行
        }

        // 打印一个正立的倒立的三角形
        for(int x=0;x<5;x++){               //控制行数
            for(int y=0;y<(5-x);y++){           //控制列数
                System.out.print("*");
            }
            System.out.println();           //换行
        }

        System.out.println("================");

        //打印一个九九乘法表
        for(int x=1;x<=9;x++){
            for(int y=1;y<=x;y++){
                // System.out.print("%d*%d=%d    "%(x,y,x*y);
                System.out.print(y+"*"+x+"="+x*y+"\t");
            }
            System.out.println();
        }

        //转义字符
        System.out.println("+++");
        System.out.println("Hello\rworld!");

        //使用continue计算1-100中偶数的和
        sum=0;
        for(i=1;i<=100;i++){
            if(i%2!=0){
                continue;
            }
            sum+=i;
        }
        System.out.println(sum);
        System.out.println("function:");
        getMax(3,5);
        String level=getLevel(78);
        System.out.println(level);
        getMultiTable(4);

    } 

    public static void getMax(int a, int b){
        int max;
        if(a>b){
            max=a;
        }else{
            max=b;
        }
        System.out.println(max);
    }

    //需求1： 定义一个函数判断一个分数的等级，把分数的等级返回给调用者。
    public static String getLevel(int score) {
        String Level;
        if(score>=90&&score<=100){
            Level="A等级";
        }else if(score>=80&&score<=89){
            Level="B等级";
        }else if(score>=70&&score<=79){
            Level="C等级";
        }else if(score>=60&&score<=69){
            Level="D等级";
        }else{
            Level="补考等级";
        }
        return Level;
    }

    //定义一个函数打印一个乘法表，不需要返回任何数据。 
    public static void getMultiTable(int row) {
        for(int i=1;i<=row;i++){
            for(int j=1;j<=i;j++){
                System.out.print(i+"*"+j+"="+i*j+"\t");
            }
            System.out.println();
        }
    
    }


}








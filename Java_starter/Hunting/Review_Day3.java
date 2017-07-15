import java.util.Random;
import java.util.Scanner;

/**
 * Review_Day3 @2017-7-13<br>
 * 说明:一般带@的语句放在不带@的语句的后面
 * since 类、方法  等元素是从哪个发布版本引入的<br>
 * see 也可参见另外的方法<br>
 * param return 用于方法<br>
 * @version v1.0
 * @author Narglc<br>
 * @see aa 查看aa方法
 * @since 1.0   
 * @param a 参数a 用于方法
 * @retrun value 返回值描述   用于方法
 * @throw 异常说明
 */
public class Review_Day3 {
	public static void main(String[] args) {
		
		//进制
		int binary=0b10;				//二进制
		System.out.println(binary);
		int oct=010;				//八进制
		System.out.println(oct);
		int hex=0xaf10;				//十六进制
		System.out.println(hex);
		boolean fact=true;
		System.out.println(fact);
		
		//强制类型转换
		int i=128;
		System.out.println(Integer.toBinaryString(i));  //查看一个数据的二进制格式
		byte by=(byte)i;			//  大数据类型==》小数据类型
		System.out.println(by);
		System.out.println(Integer.toBinaryString(by));
		
		byte b1=1;byte b2=3;
		byte b3=(byte)(b1+b2);
		System.out.println(b3);		//byte,short,char类型在运算时会先自动转换为int数据类型
		int it=1;
		it=it++;
		System.out.println("current it="+it);
		
		int a=-10;
		int b=3;
		System.out.println(a%b);
		System.out.println("单与结果："+(3>4 | 5>1));
		
		String str=7>8?"7大于8":"7不大于8";
		System.out.println(str);
		
		//产生一个随机数
		//方法一:
		System.out.println((int)(Math.random()*10));
		//方法二:
		Random rand = new Random();
		int num = rand.nextInt(11);  //生成一个0~10（包含0、10）之间的整数
		System.out.println(num);
		
		//Scanner输入
		System.out.println("输入Scanner扫描的测试:");
		Scanner scanner=new Scanner(System.in);
		int input=scanner.nextInt();
		System.out.println("刚刚输入的整数为:"+input);
		scanner.close();

		//break、continue作用于内外循环体
		outer:for (int j = 0; j < 2; j++) {
			inner:for (int j2 = 0; j2 < 3; j2++) {
				System.out.print("Inner\t");
				continue outer;     //通过这种标记的方式break外层循环
			}
			System.out.print("Outer\t");
		}//continue同理可以使用这种  标记法
		
	}
}

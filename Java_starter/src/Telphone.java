/**
 * Created by narglc on 7/12/16.
 */

//定义一个类
public class Telphone {
    //属性（成员变量）有什么
    float screen;
    float cpu;
    float mem;
    int var;


    //方法 干什么
    void call(){
        System.out.println("Telphone有打电话的功能！");
        System.out.println("var"+var);
    }
    void sendMessage(){
        System.out.println("screen:"+screen+"cpu:"+cpu+"mem:"+mem+"  Telphone有发短信的功能");
        System.out.println("var:"+var);

    }


}

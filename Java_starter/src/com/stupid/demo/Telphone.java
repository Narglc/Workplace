package com.stupid.demo;

/**
 * Created by narglc on 7/12/16.
 */

//定义一个类
public class Telphone {
    //属性（成员变量）有什么
    private float screen;
    private float cpu;
    float mem;
    public int var;

    public float getCpu() {
        return cpu;
    }

    public void setCpu(float cpu) {
        this.cpu = cpu;
        this.sendMessage();         //this 表示调用当前对象的某个方法或这属性
    }

    public float getScreen(){
        return screen;
    }

    public void setScreen(float newScreen){
        screen=newScreen;
    }

    //方法 干什么
    void call(){
        System.out.println("Telphone有打电话的功能！");
        System.out.println("var"+var);
    }
    public void sendMessage(){
        System.out.println("screen:"+screen+"cpu:"+cpu+"mem:"+mem+"  Telphone有发短信的功能");
        System.out.println("var:"+var);

    }


}

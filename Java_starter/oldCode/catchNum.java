import java.util.*;
class Demo{
    public static void main(String[] args){
        Random random = new Random();
        int num =random.nextInt(10)+1;    // 1-10
        // System.out.println(num);
        int guess=11;
        while(guess!=num){
            System.out.println("pls in a number:");
            Scanner scanner =  new Scanner(System.in);
            guess = scanner.nextInt();
            if(guess>num){
                System.out.println("bigger!");
            }else if(guess<num){
                System.out.println("smaller!");
            }
        }
        System.out.println("You got the corrected number!");
        System.out.println("The num is: "+num);
    }
}

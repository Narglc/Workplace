/**
 * Created by narglc on 7/12/16.
 */
public class initTelphone {
    public static void main(String[] args) {
        Telphone phone = new Telphone();
        phone.sendMessage();

        phone.screen=5.0f;
        phone.cpu=2.0f;
        phone.mem=3.9f;

        phone.sendMessage();
        phone.call();

    }
}

//JL3==exceptions in java
import java.util.Date;
import java.lang.Exception;

public class JL3
{
    public static void main(String[] args) {
        Date d=null;
        try {
            System.out.println(d.getTime());
        } catch (Exception e) {
            
            System.out.println(e.toString());
        }
        int a=0;
        int b=0;
        try {
            a=a/b;
        } catch (Exception e) {
            
            System.out.println(e.toString());
        }
        try {
            throw new MyE();
        } catch (Exception e) {
            
            System.out.println(e.toString());
        }
        double c=0;
        double d1=0;
        c=c/d1;
        System.out.println("c="+c);


        
    }
}

/**
 * MyE
 */
class MyE extends Exception{

@Override
public String toString() {
    
    return "WDNMD\n";
}   
}
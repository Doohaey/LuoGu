import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        BigInteger s1 = sc.nextBigInteger();
        BigInteger s2 = sc.nextBigInteger();
        BigInteger result = s1.add(s2);
        System.out.println(result);
    }
}

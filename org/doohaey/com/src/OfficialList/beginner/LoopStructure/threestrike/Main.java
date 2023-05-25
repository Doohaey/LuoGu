package intermediate;

public class Main {
    public static void main(String[] args) {
        for(int a = 123; a <= 333; a++)
        {
            int b = 2 * a;
            int c = 3 * a;
            if((a/100+a/10%10+a%10+b/100+b/10%10+b%10+c/100+c/10%10+c%10 == 1+2+3+4+5+6+7+8+9)
                    && ((a/100)*(a/10%10)*(a%10)*(b/100)*(b/10%10)*(b%10)*(c/100)*(c/10%10)*(c%10)==(1)*(2)*(3)*(4)*(5)*(6)*(7)*(8)*(9)))
                System.out.printf("%d %d %d\n",a,b,c);
        }
    }

}

package beginner.seriessummation;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int k = fetchK();
        int n = fetchN(k);
        System.out.println(n);
    }
    public static int fetchK(){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        if(k > 0 && k < 16) return k;
        else return fetchK();
    }

    public static int fetchN(int k){
        int n = 1;
        for(double sum = 0; sum <= k; n++) sum = sum + 1.0/n;
        return n - 1;
    }
}



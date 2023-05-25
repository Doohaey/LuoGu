package beginner.counttwo;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IllegalArgumentException{
        Scanner sc = new Scanner(System.in);
        //获取上下限
        int L = sc.nextInt();
        int R = sc.nextInt();

        int count = 0;
        for(int i = L; i < (R+1); i++) count += checkTwo(i);

        System.out.println(count);
    }
    public static int checkTwo(int i) {
        int countSingle;
        for(countSingle = 0; i > 0; i /= 10){
            if (i % 10 == 2) countSingle++;
        }
        return countSingle;
    }
}

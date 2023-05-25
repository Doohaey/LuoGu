package palindrome;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        int limitedSteps = 30;

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); //获取进制
        String M = sc.next(); //获取数字
        BigInteger input = new BigInteger(M,N);

        try {
            int output = findSteps(input,N,limitedSteps);
            System.out.println("STEP=" + output);
        }
        catch (Exception e){
            System.out.println("Impossible!");
        }
    }

    public static int findSteps(BigInteger input, int N, int limitedSteps) throws Exception{
        boolean isPalindrome = false;
        int count = 0;
        for(int i = 0; i < limitedSteps && !isPalindrome; i++){
            String inputAux = input.toString(N);
            StringBuilder sb = new StringBuilder();
            for (int j = inputAux.length() - 1; j >= 0; j--) sb.append(inputAux.charAt(j));
            String invert = sb.toString();
            BigInteger invertNum = new BigInteger(invert,N);

            input = input.add(invertNum);
            inputAux = input.toString(N);

            boolean isSymmetry = true;
            for (int k = 0; k < inputAux.length() / 2; k++){
                if (inputAux.charAt(k) != inputAux.charAt(inputAux.length() - 1 - k)) {
                    isSymmetry = false;
                    break;
                }
            }
            isPalindrome = isSymmetry;
            count++;
        }

        if (isPalindrome) return count;
        else throw new Exception();
    }
}

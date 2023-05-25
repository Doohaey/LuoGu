package sumfactorial;

import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] output = factorialSummation(n);
        printArray(output);
    }

    //计算和的入口
    public static int[] factorialSummation(int n) {
        int[][] arrayOfFactorials = new int[n][];//用于装载单个阶乘
        int[] sum = new int[100];//结果

        for (int i = 1; i <= n; i++) arrayOfFactorials[i - 1] = calculateFactorial(i);//将单个值计算并存放

        sum = columnSummation(arrayOfFactorials, n);
        return sum;
    }

    //计算单个值，调用竖式乘法
    public static int[] calculateFactorial(int n) {
        int[] singleFactorial = new int[100];
        Arrays.fill(singleFactorial, 0);
        singleFactorial[99] = 1;

        for (int i = 1; i <= n; i++) {
            singleFactorial = columnMultiplication(singleFactorial, i);
            if (singleFactorial[0] != 0) {
                break;
            }
        }

        return singleFactorial;
    }

    //竖式乘法，处理进位问题
    public static int[] columnMultiplication(int[] x, int n) {
        int carry = 0;
        for (int d = x.length - 1; d >= 0; d--) {
            x[d] = x[d] * n + carry;
            if (x[d] >= 10) {
                carry = x[d] / 10;
                x[d] = x[d] % 10;
            } else {
                carry = 0;
            }
        }
        return x;
    }

    //加总列表
    public static int[] columnSummation(int[][] x, int n) {
        int[] sum = new int[100];
        for (int i = 0; i < n; i++) {
            int carry = 0;
            for (int d = sum.length - 1; d >= 0; d--) {
                sum[d] += x[i][d] + carry;
                if (sum[d] >= 10) {
                    carry = sum[d] / 10;
                    sum[d] = sum[d] % 10;
                } else {
                    carry = 0;
                }
            }
        }
        return sum;
    }

    public static void printArray(int[] x) {
        boolean leadingZero = true;
        for (int value : x) {
            if (leadingZero && value != 0) {
                leadingZero = false;
            }
            if (!leadingZero) {
                System.out.print(value);
            }
        }
        System.out.println();
    }
}



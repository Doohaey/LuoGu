package beginner.torch;

import java.util.Arrays;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) throws IllegalArgumentException{
        Scanner sc = new Scanner(System.in);
        //获取方阵大小
        int n = sc.nextInt();
        //获取火把数量
        int m = sc.nextInt();
        //获取萤石数量
        int k = sc.nextInt();

        //获取火把坐标和萤石坐标
        int[][] torchList = new int[2][m];
        for(int t = 0; t < m; t++){
            torchList[0][t] = sc.nextInt();
            torchList[1][t] = sc.nextInt();
        }

        int[][] glowList = new int[2][k];
        for(int g = 0; g < k; g++){
            glowList[0][g] = sc.nextInt();
            glowList[1][g] = sc.nextInt();
        }

        //分析区域
        int S = n * n;
        boolean[][] area = new boolean[n][n];
        area = initialize(area);
        area = applyFactors(area, torchList, m, true);
        area = applyFactors(area, glowList, k, false);

        //计算并输出
        int count = countTrue(area);
        System.out.println(count);

    }

    public static boolean[][] initialize(boolean[][] area){
        for (boolean[] booleans : area) {
            Arrays.fill(booleans, true);
        }
        return area;
    }

    public static boolean[][] applyFactors(boolean[][] area, int[][] itemList, int itemCount, boolean isTorch) {
        int xt, yt;
        for (int t = 0; t < itemCount; t++) {
            for (int i = 0; i < area.length; i++) {
                for (int j = 0; j < area[i].length; j++) {
                    xt = itemList[0][t] - 1;
                    yt = itemList[1][t] - 1;
                    if (isTorch) {
                        if ((Math.abs(i - xt) < 3 && j == yt) || (Math.abs(j - yt) < 3 && i == xt) || ((Math.abs(i - xt) < 2) && (Math.abs(j - yt) < 2))) {
                            area[i][j] = false;
                        }
                    } else {
                        if ((Math.abs(i - xt) < 3) && (Math.abs(j - yt) < 3)) {
                            area[i][j] = false;
                        }
                    }
                }
            }
        }
        return area;
    }

    public static int countTrue(boolean[][] area) {
        int count = 0;
        for (boolean[] booleans : area) {
            for (boolean aBoolean : booleans) {
                if (aBoolean) count++;
            }
        }
        return count;
    }
}

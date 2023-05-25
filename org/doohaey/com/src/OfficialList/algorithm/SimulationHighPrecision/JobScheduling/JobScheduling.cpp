#include <iostream>

#define LENGTH_OF_ARRAY 7200

int main() {
    int numM, numN;
    std::cin >> numM >> numN;

    int seq[numM*numN], mac[numN][numM], proTime[numN][numM];
    for (int i = 0; i < numM*numN; i++) std::cin >> seq[i];
    for (int j = 0; j < numN; j++) {
        for (int k = 0; k < numM; k++) std::cin >> mac[j][k];
    }
    for (int x = 0; x < numN; x++) {
        for (int y = 0; y < numM; y++) std::cin >> proTime[x][y];
    }

    bool timeOcc[numM][LENGTH_OF_ARRAY] = {false};
    int procTimes[numN] = {0};
    int indexProc[numN] = {0};
    for (int i = 0; i < numM*numN; i++) {
        int selProc = seq[i] - 1;
        procTimes[selProc]++;
        int selMac = mac[selProc][procTimes[selProc] - 1] - 1;

        int countAvail = 0;
        for (int j = 0; j < LENGTH_OF_ARRAY; j++) {
            if (!(timeOcc[selMac][j]) && (j > indexProc[selProc] || indexProc[selProc] == 0)) {
                countAvail++;
            } else {
                countAvail = 0;
            }

            if (countAvail == proTime[selProc][procTimes[selProc] - 1]) {
                indexProc[selProc] = j;
                for (int k = j - countAvail + 1; k <= j; k++) timeOcc[selMac][k] = true;
                break;
            }
        }
    }

    int maxIndex = 0;
    for (int i = 0; i < numM; i++) {
        for (int j = 0; j < LENGTH_OF_ARRAY; j++) {
            if (timeOcc[i][j] && j > maxIndex) maxIndex = j;
        }
    }
    std::cout << maxIndex+1 << std::endl;
}

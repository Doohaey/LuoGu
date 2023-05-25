#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void threeWayPartition(int arr[], int begin, int end, int &i, int &j) {
    int random_index = begin + rand() % (end - begin + 1);
    std::swap(arr[random_index], arr[begin]);

    int pivot = arr[begin];
    i = begin;
    j = end;
    int p = begin + 1;

    while (p <= j) {
        if (arr[p] < pivot) {
            std::swap(arr[p], arr[i]);
            i++;
        } else if (arr[p] > pivot) {
            std::swap(arr[p], arr[j]);
            j--;
            continue;
        }
        p++;
    }
}

void quickSort(int arr[], int begin, int end) {
    if (begin < end) {
        int i, j;
        threeWayPartition(arr, begin, end, i, j);

        quickSort(arr, begin, i - 1);
        quickSort(arr, j + 1, end);
    }
}

void printArray(int arr[], int start, int end) {
    for (int i = start; i <= end; i++) {
        std::cout << arr[i];
        if (i != end) std::cout << " ";
    }
}

int main() {
    srand(time(0));
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    quickSort(arr, 0, n - 1);
    printArray(arr, 0, n - 1);

    return 0;
}

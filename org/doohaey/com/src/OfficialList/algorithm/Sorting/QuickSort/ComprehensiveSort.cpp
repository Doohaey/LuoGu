#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int THRESHOLD = 10;

void insertionSort(int arr[], int begin, int end) {
    for (int i = begin + 1; i <= end; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= begin && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

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

void hybridQuickSort(int arr[], int begin, int end) {
    if (begin < end) {
        if (end - begin + 1 <= THRESHOLD) {
            insertionSort(arr, begin, end);
        } else {
            int i, j;
            threeWayPartition(arr, begin, end, i, j);

            hybridQuickSort(arr, begin, i - 1);
            hybridQuickSort(arr, j + 1, end);
        }
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

    hybridQuickSort(arr, 0, n - 1);
    printArray(arr, 0, n - 1);

    return 0;
}

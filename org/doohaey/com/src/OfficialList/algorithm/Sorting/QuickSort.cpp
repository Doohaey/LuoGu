#include <iostream>
#include <algorithm>

int partition(int arr[], int begin, int end) {
    int i = begin + 1, j = end, pivot = arr[begin];
    while (i <= j) {
        while (i <= j && arr[i] < pivot) i++;
        while (i <= j && arr[j] > pivot) j--;
        if (i < j) std::swap(arr[i], arr[j]);
    }
    std::swap(arr[begin], arr[j]);
    return j;
}

void quickSort(int arr[], int begin, int end) {
    if (begin < end) {
        int pivot = partition(arr, begin, end);

        quickSort(arr, begin, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

void printArray(int arr[], int start, int end) {
    for (int i = start; i <= end; i++) {
        std::cout << arr[i];
        if (i != end) std::cout << " ";
    }
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    quickSort(arr, 0, n - 1);
    printArray(arr, 0, n - 1);

    return 0;
}


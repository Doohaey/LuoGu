#include <cstdio>
#include <vector>

int numElements, numQueries;

int binarySearch(const std::vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return (left < arr.size() && arr[left] == x) ? left : -1;
}

void printIdx(int index, int i){
    if (index != -1) {
            printf("%d", index + 1);
        } else {
            printf("-1");
        }

        if (i == numQueries - 1){
            printf("\n");
        } else {
            printf(" ");
        }
}

int main() {
    scanf("%d %d", &numElements, &numQueries);

    std::vector<int> elements(numElements);
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &elements[i]);
    }

    for (int i = 0; i < numQueries; i++) {
        int query;
        scanf("%d", &query);

        int index = binarySearch(elements, query);

        printIdx(index,i);
    }

    return 0;
}



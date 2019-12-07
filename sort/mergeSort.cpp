#include <iostream>
using namespace std;
const int MAXN = 1000;

void merge(int* arr, int l1, int r1, int l2, int r2) {
    int temp[MAXN];
    int p1 = l1, p2 = l2, p = 0;
    while (p1 <= r1 && p2 <= r2) {
        if (arr[p1] >= arr[p2])
            temp[p++] = arr[p2++];
        else temp[p++] = arr[p1++];
    }
    while (p1 <= r1)
        temp[p++] = arr[p1++];
    while (p2 <= r2)
        temp[p++] = arr[p2++];
    for (int i = 0; i < p; i++)
        arr[l1 + i] = temp[i];
}

void mergeSort(int* arr, int left, int right) {
    if (left >= right) return ;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, mid + 1, right);
}

int main(void) {
    
    int left = 0, right = 7;
    int num[100] = { 1, 10, 60, 80, 53, 43, 65, 2 };
    mergeSort(num, left, right);
    for (int i = left; i <= right; i++)
        cout << num[i] << " ";
    cout << endl;

    return 0;
}

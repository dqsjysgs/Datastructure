#include <iostream>
using namespace std;

void quicksort(int arr[], int left, int right) {
    if (left > right) return ;
    int pivot = arr[left];
    int j = right, i = left;
    while (i != j) {
        while (arr[j] >= pivot && i < j)
            j--;
        while (arr[i] <= pivot && i < j)
            i++;
        if (i < j) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[left] = arr[i];
    arr[i] = pivot;
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}

int main(void) {

    int num[100] = { 22, 3, 7, 1, 8, 9, 35, 56, 6, 3, 6 };
    quicksort(num, 0, 2);

    for (int i = 0; i <= 2; i++)
        cout << num[i] << " ";
    cout << endl;

    return 0;
}

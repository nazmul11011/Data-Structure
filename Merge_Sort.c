#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    
    int i, j, k;
    int size_left = mid - left + 1;
    int size_right = right - mid;

    int L[size_left], R[size_right];

    for (i = 0; i < size_left; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < size_right; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < size_left && j < size_right) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < size_left) {
        arr[k++] = L[i++];
    }

    while (j < size_right) {
        arr[k++] = R[j++];
    }
}

void merge_sort(int arr[], int left, int right){
    if(left>= right){
        return;
    }

    int mid = (left+right)/2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);

    merge(arr, left, mid, right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    merge_sort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
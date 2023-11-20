#include <stdio.h>
#include<stdlib.h>

//sorting of the elements
int partition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i + 1];
    arr[i + 1] = arr[h];
    arr[h] = t;

    return i + 1;
}

int Ksm(int arr[], int l, int h, int k) {  // here pindex=pivotindex
    if (k>0&&k <=h - l + 1) {
        int pindex = partition(arr, l, h);
        if (pindex - l==k - 1) { // if index is in the kth position
            return arr[pindex];
        }
        if (pindex - l>k - 1) {  // if the index is more than k, it will search in the left subarray
            return Ksm(arr,l,pindex - 1,k);
        }
        return Ksm(arr,pindex + 1,h,k-pindex+l - 1);   // Otherwise, it will search in the right subarray
    }
    return -1;  // if k is out of bounds, return -1
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid size of the array\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k > 0 && k <= n) {
        int res=Ksm(arr, 0, n - 1, k);
        printf("The %dth smallest element is: %d\n", k, res);
    } else {
        printf("Invalid value of k\n");
    }
    
    return 0;
}

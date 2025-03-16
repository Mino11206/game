#include <iostream>
#include <time.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int a = 0;
    int n1 = mid - left + 1;
    int* sub1 = new int[n1];
    for(int i = left; i <= mid; i++) {
        sub1[a++] = arr[i];
    }

    int b = 0;
    int n2 = right - mid;
    int* sub2 = new int[n2];
    for(int i = mid + 1; i <= right; i++) {
        sub2[b++] = arr[i];
    }

    a = 0;
    b = 0;
    int c = left;
    while(a < n1 && b < n2) {
        if(sub1[a] < sub2[b]) {
            arr[c++] = sub1[a++];
        } else{
            arr[c++] = sub2[b++];
        }
    }
    while(a < n1) {
        arr[c++] = sub1[a++];
    } 
    while(b < n2) {
        arr[c++] = sub2[b++];
    }
    delete[] sub1;
    delete[] sub2;
}

void mergeSort(int arr[], int left, int right) {
    if(left >= right) return;
    int mid = (right + left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
    
}

void countingSort(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    int* size = new int[max + 1]();
    
    for(int i = 0; i < n; i++) {
       size[arr[i]]++;
    }

    int j = 0;
    for(int i = 0; i < max + 1; i++) {
        int count = size[i];
        while(count != 0) {
            arr[j++] = i;
            count--;
        }
    }
    delete[] size;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void radixSort(int arr[], int n) {
    int max = findMax(arr, n); 
    int exp = 1;            

    int output[n];

    while (max / exp > 0) {
        int count[10] = {0}; 

        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[--count[digit]] = arr[i];
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
        exp *= 10;
    }
}

int main() {
    srand(time(0));
    int n = 0;
    cout << "So phan tu la: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    
    int arr1[n];
    for(int i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }

    int arr2[n];
    for(int i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }

    clock_t start = clock();
    mergeSort(arr, 0, n -1);
    clock_t end = clock();
    cout << "Merge Sort Time: " << (float)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    
    clock_t start1 = clock();
    countingSort(arr1, n);
    clock_t end1 = clock();
    cout << "Counting Sort Time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << " seconds" << endl;

    clock_t start2 = clock();
    radixSort(arr2, n);
    clock_t end2 = clock();
    cout << "Radix Sort Time: " << (float)(end2 - start2) / CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}
#include <iostream>
#include <time.h>
using namespace std;


int* generateRandNum(int n) {
    int* ans = new int[n];

    for(int i = 0; i < n; i++) {
        ans[i] = rand() % 1000;
    }

    return ans;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while(i <= j) {
        while(i <= j && arr[i] < pivot) i++;
        while(i <= j && arr[j] > pivot) j--;
        if(i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    return i;
} 

void quickSort(int arr[], int left, int right) {
    if(left >= right) return;
    int pivotIndex = partition(arr, left , right);
    if(left < pivotIndex - 1)quickSort(arr, left, pivotIndex - 1);
    if(pivotIndex + 1 < right)quickSort(arr, pivotIndex + 1, right);
}

void heapify(int arr[], int n, int i) {
    int max = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if(left < n && arr[left] > arr[max]) max = left;
    if(right < n && arr[right] > arr[max]) max = right;

    if(max != i){
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
    
}

void buildMaxHeap(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n); 
    for(int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main() {
    srand(time(0));
    int n;
    cout << "So phan tu cua mang: ";
    cin >> n;

    int* arr = generateRandNum(n);
    cout << endl;

    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    cout << "Quick Sort Time: " << (float)(end - start) / CLOCKS_PER_SEC << "seconds" << endl;
    
    int* arr1 = generateRandNum(n);
    clock_t start1 = clock();
    heapSort(arr1, n);
    clock_t end1 = clock();
    cout << "Heap Sort Time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << "seconds" << endl;

    delete[] arr;
    delete[] arr1;
        return 0;
}
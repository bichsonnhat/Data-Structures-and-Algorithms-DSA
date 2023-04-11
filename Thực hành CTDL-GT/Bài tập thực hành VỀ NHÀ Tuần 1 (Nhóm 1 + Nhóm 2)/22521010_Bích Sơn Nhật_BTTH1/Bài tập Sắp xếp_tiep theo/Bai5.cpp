#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int a[N];
int n;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionHead(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = low - 1; 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partitionMid(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2]; 
    int i = low - 1; 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partitionTail(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    stack<int> stk;
    stk.push(low);
    stk.push(high);
    while (!stk.empty()) {
        high = stk.top();
        stk.pop();
        low = stk.top();
        stk.pop();
 
        int pi = partitionTail(arr, low, high);
 
        if (pi - 1 > low) {
            stk.push(low);
            stk.push(pi - 1);
        }
 
        if (pi + 1 < high) {
            stk.push(pi + 1);
            stk.push(high);
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    return 0;
}
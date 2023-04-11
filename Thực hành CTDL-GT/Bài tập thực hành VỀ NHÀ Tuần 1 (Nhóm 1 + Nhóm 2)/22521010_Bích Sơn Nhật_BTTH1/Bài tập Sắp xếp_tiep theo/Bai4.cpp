#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void heapify(vector<int>& arr, int n, int i, int& cmpCount, int& assignCount) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    cmpCount++;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    cmpCount++;

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    cmpCount++;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        assignCount += 3;
        heapify(arr, n, largest, cmpCount, assignCount);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    int cmpCount = 0;
    int assignCount = 0;

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, cmpCount, assignCount);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        assignCount += 3;
        heapify(arr, i, 0, cmpCount, assignCount);
    }

    cout << "Heap Sort comparisons: " << cmpCount << ", assignments: " << assignCount << endl;
}

int partition(vector<int>& arr, int low, int high, int& cmpCount, int& assignCount) {
    int pivotValue = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        cmpCount++;
        if (arr[j] <= pivotValue) {
            i++;
            swap(arr[i], arr[j]);
            assignCount += 3;
        }
    }
    swap(arr[i + 1], arr[high]);
    assignCount += 3;
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int& cmpCount, int& assignCount) {
    if (low < high) {
        int pivot = partition(arr, low, high, cmpCount, assignCount);
        quickSort(arr, low, pivot - 1, cmpCount, assignCount);
        quickSort(arr, pivot + 1, high, cmpCount, assignCount);
    }
}

void merge(vector<int>& arr, int l, int m, int r, int& cmpCount, int& assignCount) {
    int n1 = m - l + 1;
    vector<int> L(n1);
    vector<int> R(r - m);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < r - m; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < r - m) {
        cmpCount++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            assignCount++;
            i++;
        }
        else {
            arr[k] = R[j];
            assignCount++;
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        assignCount++;
        i++;
        k++;
    }

    while (j < r - m) {
        arr[k] = R[j];
        assignCount++;
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r, int& cmpCount, int& assignCount) {
    if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m, cmpCount, assignCount);
    mergeSort(arr, m + 1, r, cmpCount, assignCount);
    merge(arr, l, m, r, cmpCount, assignCount);
    }
}


int main(){
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    heapSort(a);
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    int mergeSortx = 0, mergeSorty = 0;
    int quickSortx = 0, quickSorty = 0;
    mergeSort(a, 0, n - 1, mergeSortx, mergeSorty);
    cout << "Merge Sort comparisons: " << mergeSortx << ", " << "assignments: " << mergeSorty << endl;
    quickSort(a, 0, n - 1, quickSortx, quickSorty);
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}

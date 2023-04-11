#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n;
int a[N];

void SelectionSort(){
    for (int i = 0; i + 1 < n; ++i){
    	int pos = i;
    	for (int j = i + 1; j < n; ++j){
    		if (a[j] < a[pos]){
    			pos = j;
    		}
    	}
    	swap(a[i], a[pos]);
    }
}

void InsertionSort(){
	for (int i = 1; i < n; ++i){
		int cur = a[i];
		int pos = i - 1;
		while (pos >= 0 && a[pos] > cur){
			a[pos + 1] = a[pos];
			pos -= 1;
		}
		a[pos + 1] = cur;
	}
}

void InterchangeSort(){
	for (int i = 0; i + 1 < n; ++i){
		for (int j = i + 1; j < n; ++j){
			if (a[i] > a[j]){
				swap(a[i], a[j]);
			}
		}
	}
}

void qSortMid(int l, int r){
	int i = l;
	int j = r;
	int mid = (l + r) >> 1;
	int pivot = a[mid];
	while (i < j){
		while (a[i] < pivot){
			i++;
		}
		while (a[j] > pivot){
			j--;
		}
		if (i <= j){
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	for (int i = 0; i < n; ++i){
		cout << a[i] << ' ';
	} cout << endl;
	if (l < j) qSortMid(l, j);
	if (i < r) qSortMid(i, r);
}

void buildHeap(int a[], int n, int i){
	int par = i;
    int lf_node = 2 * i + 1;
    int rf_node = 2 * i + 2;
    if (lf_node < n && a[lf_node] > a[par]){
    	par = lf_node;
    }
    if (rf_node < n && a[rf_node] > a[par]){
    	par = rf_node;
    }
    // cout << i << ' ' << lf_node << ' ' << rf_node << endl;
    // cout << a[i] << ' ' << a[lf_node] << ' ' << a[rf_node] << endl;
    if (par != i){
    	swap(a[i], a[par]);
    	// cout << "After Swap: ";
    	// for (int i = 0; i < n; ++i) cout << a[i] << ' '; cout << endl << endl;
    	buildHeap(a, n, par);
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }
    SelectionSort();
    InsertionSort();
    InterchangeSort();
    qSortMid(0, n - 1);
    for (int i = n / 2 - 1; i >= 0; --i){
    	buildHeap(a, n, i);
    }

    for (int i = n - 1; i >= 0; --i){
    	swap(a[0], a[i]);
    	buildHeap(a, i, 0);
    }

    for (int i = 0; i < n; ++i){
    	cout << a[i] << ' ';
    }
    return 0;
}
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
int main(){
    cin >> n;

    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }

    SelectionSort();
    InsertionSort();
    InterchangeSort();
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
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n;
int a[N];

void merge(int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	vector <int> L(n1), R(n2);

	for (int i = 0; i < n1; ++i){
		L[i] = a[left + i];
	}

	for (int j = 0; j < n2; ++j){
		R[j] = a[mid + 1 + j];
	}

	int k = left;
	int i = 0, j = 0;
    	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
		    a[k++] = L[i++];
		} else {
		    a[k++] = R[j++];
		};
    	}

	while (i < n1) a[k++] = L[i++];
	while (j < n2) a[k++] = R[j++];
}

void mergeSort(int l, int r){
	if (l < r){
		int mid = (l + r) >> 1;
		mergeSort(l, mid);
		mergeSort(mid + 1, r);

		merge(l, mid, r);
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("TRAINING.INP","r",stdin);
        freopen("TRAINING.OUT","w",stdout);
    #endif
    cin >> n;
    
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }

    mergeSort(0, n - 1);

    for (int i = 0; i < n; ++i){
    	cout << a[i] << ' ';
    }
    return 0;
}

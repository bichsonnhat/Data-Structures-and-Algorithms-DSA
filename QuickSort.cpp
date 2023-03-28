#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int n;
int a[N];

void qSort(int l, int r){
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

	if (l < j) qSort(l, j);
	if (i < r) qSort(i, r);
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

    qSort(0, n - 1);

    for (int i = 0; i < n; ++i){
    	cout << a[i] << ' ';
    }
    return 0;
}
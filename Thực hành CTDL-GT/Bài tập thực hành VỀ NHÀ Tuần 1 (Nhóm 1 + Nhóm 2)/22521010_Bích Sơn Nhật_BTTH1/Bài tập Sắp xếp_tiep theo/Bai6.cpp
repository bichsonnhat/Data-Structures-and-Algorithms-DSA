#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N];
int n;

void qSortHead(int l, int r){
	int i = l;
	int j = r;
	int mid = (l + r) >> 1;
	int pivot = a[l];
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
	if (l < j) qSortHead(l, j);
	if (i < r) qSortHead(i, r);
}
void qSortTail(int l, int r){
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
	if (l < j) qSortTail(l, j);
	if (i < r) qSortTail(i, r);
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
	if (l < j) qSortMid(l, j);
	if (i < r) qSortMid(i, r);
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    qSortHead(1, n);
	qSortMid(1, n);
	qSortTail(1, n);
	for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}
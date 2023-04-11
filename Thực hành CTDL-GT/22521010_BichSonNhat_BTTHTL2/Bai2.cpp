#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool found = 0;
void binarySearch(vector <int> a, int L, int R, int X){
	if (found == 1){
		return;
	}
	int mid = (L + R) >> 1;
	if (a[mid] == X){
		found = 1;
		return;
	}
	if (a[mid] < X){
		binarySearch(a, mid + 1, R, X);
	} else {
		binarySearch(a, L, mid - 1, X);
	}
}

int main(){
    int n, X; cin >> n >> X;
    vector <int> a(n);
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    binarySearch(a, 0, n - 1, X);
    if (found == 1){
    	cout << "Can Found!";
    } else {
    	cout << "Not Found!";
    }
    return 0;
}
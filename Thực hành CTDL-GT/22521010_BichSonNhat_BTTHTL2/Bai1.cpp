#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector <int> array, int n, int X){
	for (int i = 0; i < n; ++i){
		if (array[i] == X){
			return true;
		}
	}
	return false;
}

bool binarySearch(vector <int> array, int n, int X){
	sort(array.begin(), array.end());
	int L = 0, R = n - 1;
	while (L <= R){
		int mid = (L + R) >> 1;
		if (array[mid] == X){
			return true;
		}
		if (array[mid] < X){
			L = mid + 1;
		} else {
			R = mid - 1;
		}
	}
	return false;
}

int main(){
    int n, X; cin >> n >> X;
    vector <int> a(n);

    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    bool res = linearSearch(a, n, X);
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    int duration_1 = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    chrono::high_resolution_clock::time_point t3 = chrono::high_resolution_clock::now();
    res = binarySearch(a, n, X);
    chrono::high_resolution_clock::time_point t4 = chrono::high_resolution_clock::now();

    int duration_2 = std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count();
    cout << "linearSearch TOOK: " << duration_1 << "ms\n";
    cout << "binarySearch TOOK: " << duration_2 << "ms";
    return 0;
}
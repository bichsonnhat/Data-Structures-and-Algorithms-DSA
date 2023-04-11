#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> a = {12, 8, 2, 14, 3, 5, 10, 15, 36};
    vector <int> odd, even;
    vector <int> res(9);
    for (auto i : a){
    	if (i & 1) odd.push_back(i);
    		else even.push_back(i);
    }
    for (int i = 0; i < 9; ++i){
    	if (a[i] & 1) res[i] = 0;
    		else res[i] = 1;
    }
    sort(odd.begin(), odd.end(), greater <int>());
    sort(even.begin(), even.end());
    for (auto i : even) cout << i << ' '; cout << endl;
    for (auto i : odd) cout << i << ' '; cout << endl;
	int idx = 0;
	for (int i = 0; i < 9; ++i){
		if (res[i] == 0){
			res[i] = odd[idx++];
		}
	}
	idx = 0;
	for (int i = 0; i < 9; ++i){
		if (res[i] == 1){
			res[i] = even[idx++];
		}
	}
	for (auto i : res) cout << i << ' ';
	cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int a[N];
int n;

void CauA(){
	vector <int> neg, pos;
	for (int i = 0; i < n; ++i){
		if (a[i] < 0) neg.push_back(a[i]);
			else pos.push_back(a[i]);
	}
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end(), greater <int>());
	for (auto i : neg) cout << i << ' ';
	for (auto i : pos) cout << i << ' ';
	cout << endl;
}

void CauB(){
	vector <int> neg, pos;
	for (int i = 0; i < n; ++i){
		if (a[i] < 0) neg.push_back(a[i]);
			else pos.push_back(a[i]);
	}
	sort(neg.begin(), neg.end(), greater <int>());
	sort(pos.begin(), pos.end());
	for (auto i : neg) cout << i << ' ';
	for (auto i : pos) cout << i << ' ';
	cout << endl;
}

void CauC(){
	vector <int> neg, pos;
	for (int i = 0; i < n; ++i){
		if (a[i] < 0) neg.push_back(a[i]);
			else pos.push_back(a[i]);
	}
	sort(neg.begin(), neg.end(), greater <int>());
	sort(pos.begin(), pos.end());
	for (auto i : pos) cout << i << ' ';
	for (auto i : neg) cout << i << ' ';
	cout << endl;
}

void CauD(){
	vector <int> neg, pos;
	for (int i = 0; i < n; ++i){
		if (a[i] < 0) neg.push_back(a[i]);
			else pos.push_back(a[i]);
	}
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end(), greater <int>());
	for (auto i : pos) cout << i << ' ';
	for (auto i : neg) cout << i << ' ';
	cout << endl;
}

void CauE(){
	vector <int> neg, pos;
	vector <int> res(n);
	for (int i = 0; i < n; ++i){
		if (a[i] < 0) neg.push_back(a[i]), res[i] = 0;
			else pos.push_back(a[i]), res[i] = 1;
	}

	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end(), greater <int> ());
	int idx = 0;
	for (int i = 0; i < n; ++i){
		if (res[i] == 0){
			res[i] = neg[idx++];
		}
	}
	idx = 0;
	for (int i = 0; i < n; ++i){
		if (res[i] == 1){
			res[i] = pos[idx++];
		}
	}
	for (auto i : res) cout << i << ' ';
	cout << endl;
}
int main(){
    cin >> n;

    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }

    CauA();
    CauB();
    CauC();
    CauD();
    CauE();

    return 0;
}
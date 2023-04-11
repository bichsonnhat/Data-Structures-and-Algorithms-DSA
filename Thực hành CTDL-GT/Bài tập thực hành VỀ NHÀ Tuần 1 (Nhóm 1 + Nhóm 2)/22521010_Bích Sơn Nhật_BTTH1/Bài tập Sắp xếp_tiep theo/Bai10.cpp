#include <bits/stdc++.h>
using namespace std;

const int N = 100;
struct poly{
	bool sign;
	int coef;
	int deg; // 1 -> 99
};

poly a[N];
int n;

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
    	cin >> a[i].sign >> a[i].coef >> a[i].deg;
    }
    sort(a, a + n, [&](poly X, poly Y) -> bool{
    	return (X.deg < Y.deg);
    });

    for (int i = 0; i < n; ++i){
    	cout << a[i].sign << ' ' << a[i].coef << ' ' << a[i].deg << endl;
    }
    return 0;
}
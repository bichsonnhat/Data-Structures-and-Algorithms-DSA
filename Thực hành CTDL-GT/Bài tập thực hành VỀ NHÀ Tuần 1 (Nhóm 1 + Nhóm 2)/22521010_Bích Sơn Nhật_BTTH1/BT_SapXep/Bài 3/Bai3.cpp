#include <bits/stdc++.h>
using namespace std;

const int N = 100;
struct info{
	int mssv;
	string name;
	int yy;
	bool gt;
	float avg;
};

info a[N];
int n;

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i){
    	cin >> a[i].mssv >> a[i].name >> a[i].yy >> a[i].gt >> a[i].avg;
    }

    sort(a, a + n, [&](info x, info y) -> bool{
    	return (x.mssv < y.mssv);
    });

    for (int i = 0; i < n; ++i){
    	cout << a[i].mssv << ' ' << a[i].name << ' ' << a[i].yy << ' ' << a[i].gt << ' ' << a[i].avg << endl;
    }

    sort(a, a + n, [&](info x, info y) -> bool{
    	return (x.avg > y.avg);
    });

    for (int i = 0; i < n; ++i){
    	cout << a[i].mssv << ' ' << a[i].name << ' ' << a[i].yy << ' ' << a[i].gt << ' ' << a[i].avg << endl;
    }
    
    return 0;
}
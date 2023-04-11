#include <vector>
#include <iostream>
using namespace std;


bool isPrime(int X){
	if (X <= 1){
		return false;
	}
	for (int i = 2; i * i <= X; ++i){
		if (X % i == 0){
			return false;
		}
	}
	return true;
}
int main(){
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    	if (isPrime(a[i])){
    		cout << a[i] << ' ';
    	}
    }
    return 0;
}
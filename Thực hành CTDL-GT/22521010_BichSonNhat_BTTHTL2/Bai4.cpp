#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 5;

bool gen[N];

void getSubarray(vector <int> a, int n){
	for (int i = 0; i < n; ++i){
		if (gen[i]){
			cout << a[i] << ' ';
		}
	}
	cout << endl;
}
void generate(int i, vector <int> a, int n){
	for (int j = 0; j <= 1; ++j){
		gen[i] = j;
		if (i == n - 1){
			getSubarray(a, n);
		} else {
			generate(i + 1, a, n);
		}
	}
}
int main(){
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    }
    generate(0, a, n);
    return 0;
}
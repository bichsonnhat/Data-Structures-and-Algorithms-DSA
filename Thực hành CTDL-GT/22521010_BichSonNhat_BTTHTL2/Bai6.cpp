#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
        ans += 1;
        for (int j = i + 1; j < n; ++j){
            if (a[j] > a[j - 1]){
                ans += 1;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
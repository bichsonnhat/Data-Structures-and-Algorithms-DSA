#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int posL = 0, posR = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i){
        int cur = a[i];
        int j = i + 1;
        int len = 1;
        while (j < n){
            if (a[j] > cur){
                cur = a[j];
                len += 1;
                j++;
            } else {
                break;
            }
        }
        if (len > ans){
            ans = len;
            posL = i;
            posR = j;
        }
    }
    cout << ans << endl;
    for (int i = posL; i < posR; ++i){
        cout << a[i] << ' ';
    }
    return 0;
}
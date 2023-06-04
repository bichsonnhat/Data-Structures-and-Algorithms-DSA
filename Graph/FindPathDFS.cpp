#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector <int> adj[n];
    vector <bool> vis(n, 0);
    vector <char> h(n);
    map <char, int> pos;

    for (int i = 0; i < n; ++i){
        char ch; cin >> ch;
        pos[ch] = i; h[i] = ch;
    }

    while (m--){
        char u, v; cin >> u >> v;
        adj[pos[u]].push_back(pos[v]);
    }

    function <void(int, int, vector <int>, int&)> DFS = [&](int u, int d, vector <int> path, int &cnt){
        vis[u] = true;
        path.emplace_back(u);
        if (u == d){
            cnt += 1;
            for (auto i : path) cout << h[i] << ' ';
            cout << endl;
        } else {
            for (auto v : adj[u]){
                if (!vis[v]) DFS(v, d, path, cnt);
            }
        }
        path.pop_back();
        vis[u] = false;
    };

    int q; cin >> q;
    while (q--){
        char s, t; cin >> s >> t;
        vector <int> p;
        int cnt = 0;
        for (int i = 0; i < n; ++i) vis[i] = false;
        DFS(pos[s], pos[t], p, cnt);
        if (!cnt) cout << "no_path\n";
    }
    return 0;
}

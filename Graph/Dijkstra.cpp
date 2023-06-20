#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
const int oo = 1e9;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector <ii> adj[n];
    vector <char> h(n);
    map <char, int> pos;

    for (int i = 0; i < n; ++i){
        char ch; cin >> ch;
        pos[ch] = i; h[i] = ch;
    }

    while (m--){
        char u, v; int w; cin >> u >> v >> w;
        adj[pos[u]].push_back({w, pos[v]});
    }

    function <void(int, int)> Dijkstra = [&](int s, int t){
        vector <int> d(n);
        for (int i = 0; i < n; ++i){
            d[i] = +oo;
        }

        vector <int> trace(n);
        d[s] = 0;
        queue <ii> pq;
        pq.push({0, s});
        while (!pq.empty()){
            int u = pq.front().second;
            int du = pq.front().first;
            pq.pop();
            for (auto alpha : adj[u]){
                int v = alpha.second, uv = alpha.first;
                if (d[v] > d[u] + uv){
                    d[v] = d[u] + uv;
                    trace[v] = u;
                    pq.push({d[v], v});
                }
            }
        }

        if (d[t] == +oo){
            cout << "no_path\n";
            return;
        } 

        vector <int> path;
        int dist = t;
        while (t != s){
            path.emplace_back(t);
            t = trace[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (auto i : path) cout << h[i] << ' '; cout << d[dist] << endl;
    };

    int q; cin >> q;
    while (q--){
        char u, v; cin >> u >> v;
        Dijkstra(pos[u], pos[v]);
    }
    return 0;
}
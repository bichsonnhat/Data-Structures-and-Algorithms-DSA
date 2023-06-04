#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <int> adj[n];
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

    function <void(int, int)> BFS = [&](int src, int dest){
        queue <vector <int> > q;
        vector <int> path;
        path.emplace_back(src);
        q.push(path);
        bool est = 0;
        auto isMatch = [&](vector <int> p, int u) -> bool{
            for (auto i : p){
                if (i == u){
                    return true;
                }
            }
            return false;
        };

        while (!q.empty()){
            path = q.front(); q.pop();
            if (path.back() == dest){
                est |= 1;
                for (auto i : path){
                    cout << h[i] << ' ';
                }
                cout << endl;
            }

            for (auto i : adj[path.back()]){
                if (!isMatch(path, i)){
                    vector <int> newPath(path);
                    newPath.emplace_back(i);
                    q.push(newPath);
                }
            }
        }

        if (!est) cout << "no_path\n";
    };

    int q; cin >> q;
    while (q--){
        char s, t; cin >> s >> t;
        BFS(pos[s], pos[t]);
    }
    return 0;
}

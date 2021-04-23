#include <bits/stdc++.h>

using namespace std;

#define P pair<int,int>
#define X first
#define Y second

const int MN = 100101;

int N, h[MN];
vector<P> g[MN];

void dfs(int n, int prv) {
    for(auto next : g[n]) {
        int v = next.X;
        int w = next.Y;
        if(v == prv) continue;
        
        h[v] = h[n] + w;
        dfs(v, n);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int u, v;    cin >> u >> v;
        while(v != -1){
            int w;  cin >> w;      
            g[u].push_back({v, w});
            cin >> v;
        }
    }
    
    dfs(1, 0);
    int mx = 1;
    for(int i = 1; i <= N; i++) 
        if(h[mx] < h[i])
            mx = i;
    
    memset(h, 0, sizeof(h));
    dfs(mx, 0);
    for(int i = 1; i <= N; i++)
        if(h[mx] < h[i])
            mx = i;
    
    cout << h[mx];
}

#include <bits/stdc++.h>

using namespace std;

const int MN = 10101;
int N, w[MN];
int dp[MN][2];
vector<int> g[MN];
vector<int> res;
int dfs(int n, int prv, bool chk) {
    int &ret = dp[n][chk];
    if(chk) ret = w[n];
    else ret = 0;

    for(int next : g[n]) {
        if(next == prv) continue;
        if(chk)
            ret += dfs(next, n, false);
        else {
            int a = dfs(next, n, true);
            int b = dfs(next, n, false);
            ret += max(a, b);
        }
    }

    return ret;
}

void dfs2(int n, int prv, bool chk) {
    if(chk) res.push_back(n);
    for(int next : g[n]) {
        if(next == prv) continue;

        if(chk) dfs2(next, n, 0);
        else {
            if(dp[next][1] > dp[next][0])
                dfs2(next, n, true);
            else
                dfs2(next, n, false);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> w[i];
    for(int i = 0; i < N-1; i++){
        int u, v;   cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    g[0].push_back(1);

    cout << dfs(0, -1, false) << '\n';
    dfs2(0, -1, false);
    sort(res.begin(), res.end());
    for(int a : res)
        cout << a << ' ';
}

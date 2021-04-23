#include <bits/stdc++.h>

using namespace std;

const int MN = 1001010;

map<int,int> m;
vector<int> nodes;
bool node_chk[MN];
int par[MN];
bool chk = true;

int main(void)
{
    ios::sync_with_stdio(false);    cin.tie(NULL);
    int T=1;
    while(1) {
        int u, v;   cin >> u >> v;
        if(u == -1 && v == -1) break;
        if(!u && !v) {
            cout << "Case " << T++ << " is a tree.\n";
            continue;
        }

        m[v]++;
        par[v] = u;
        if(!node_chk[u]) {
            nodes.push_back(u);
            node_chk[u] = true;
        }
        if(!node_chk[v]) {
            nodes.push_back(v);
            node_chk[v] = true;
        }
        while(1) {
            cin >> u >> v;
            if(!u && !v) break;

            m[v]++;
            par[v] = u;

            if(!node_chk[u]) {
                nodes.push_back(u);
                node_chk[u] = true;
            }
            if(!node_chk[v]) {
                nodes.push_back(v);
                node_chk[v] = true;
            }
        }
        int root_cnt = 0;
        for(int a : nodes) {
            int tmp = m[a];
            if(!tmp) root_cnt++;
            else if(tmp != 1) chk = false;
        }

        if(chk && root_cnt == 1)
            cout << "Case " << T++ << " is a tree.\n";
        else
            cout << "Case " << T++ << " is not a tree.\n";

        for(int a : nodes)  {
            node_chk[a] = false;
            par[a] = 0;
        }
        nodes.clear();
        m.clear();
        chk = true;
    }
}

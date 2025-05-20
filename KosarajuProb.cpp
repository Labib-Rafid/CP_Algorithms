#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const ll N = 1e5+7LL;

vector<ll> vis(N, 0);

void dfs(ll node, vector<ll> adj[]){
    ll i, j, k;
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj);
        }
    }
}

int main(){
    ll ttt = 1, n, i, k, j, m;
    //cin >> ttt;
    while(ttt--){
        cin >> n >> m;
        vector<ll> adj[n + 5], rev_adj[n + 5];
        for(i = 0; i < m; i++){
            ll k1, k2;
            cin >> k1 >> k2;
            adj[k1].pb(k2);
            rev_adj[k2].pb(k1);
        }

        dfs(1, adj);

        for(i = 1; i <= n; i++){
            if(!vis[i]) {
                cout << "NO\n" << 1 << " " << i << '\n';
                return 0;
            }
        }

        for(i = 0; i <= n; i++)
            vis[i] = 0;

        dfs(1, rev_adj);

        for(i = 1; i <= n; i++){
            if(!vis[i]) {
                cout << "NO\n" << i << " " << 1 << '\n';
                return 0;
            }
        }
        cout << "YES\n";
    }
}

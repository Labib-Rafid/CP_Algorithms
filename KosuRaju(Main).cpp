#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const ll N = 1e5+7LL;

vector<ll> adj[N], rev[N], order, ans(N);
vector<ll> vis(N);

ll cnt = 0;

void dfs(ll node){
    vis[node] = 1;
    //cnt++;
    //order.pb(node);
    for(auto it : adj[node]){
        if(!vis[it]) dfs(it);
    }
    order.pb(node);
}

void dfs_rev(ll node, ll cmp){
    vis[node] = 1;
    ans[node] = cmp;
    for(auto it : rev[node]){
        if(!vis[it]) dfs_rev(it, cmp);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ttt = 1, n, i, j, k, m, x, q = 0;
    //cin >> ttt;
    while (ttt--){
        cin >> n >> m;
        for(i = 0; i <= n; ++i) adj[i].clear();
        for(i = 0; i <= n; ++i) rev[i].clear();
        while(m--){
            cin >> k >> x;
            adj[k].pb(x);
            rev[x].pb(k);
        }
        for(q = 0; q <= n; ++q) vis[q] = 0;
        for(i = 1; i <= n; ++i){
            cnt = 0;
            if(!vis[i]) dfs(i);
        }
        //for(auto it : order) cout << it << ' ';
        //cout << endl;
        reverse(order.begin(), order.end());
        ll comp = 0;
        for(q = 0; q <= n; ++q) vis[q] = 0;
        for(q = 0; q <= n; ++q) ans[q] = 0;

        ll compo = 1;
        for(auto it : order){
            if(!vis[it]){
                dfs_rev(it, compo);
                compo++;
            }
        }
        cout << compo-1 << '\n';
        for(i = 1; i <= n; ++i) cout << ans[i] << ' ';
    }

    return 0;
}

/*

L - Planets and Kingdoms CSES - 1683


*/

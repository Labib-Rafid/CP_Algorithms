
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

struct info{
    ll u, v, w;
};

vector<info> edge;
vector<ll> dist(1007);

bool bellmanFord(ll src, ll n, ll m){
    ll i, j, k;
    for(i = 0; i <= n; i++) dist[i] = LLONG_MAX;
    bool cycle;
    dist[src] = 0;
    for(i = 0; i < n; i++){
        cycle = 0;
        for(j = 0; j < edge.size(); ++j){
            ll u = edge[j].u;
            ll v = edge[j].v;
            ll w = edge[j].w;

            if(dist[u] != LLONG_MAX ) {
                if(dist[u] + w < dist[v]) {
                    dist[v] = max(LLONG_MIN, dist[u] + w);
                    cycle = 1;
                }
            }
        }
        if(!cycle ) return 0;
    }
    return 1;
}

int main(){
    ll ttt = 1, n, i, k, j, m;
    cin >> ttt;
    while(ttt--){
        cin >> n >> m;
        edge.clear();
        for(i = 0; i < m; i++){
            ll k1, k2, k3;
            cin >> k1 >> k2 >> k3;
            edge.pb({k1, k2, k3});
        }
        if(bellmanFord(0, n, m)){
            cout << "possilbe\n";
        }
        else{
            cout << "not possible\n";
        }
    }
}

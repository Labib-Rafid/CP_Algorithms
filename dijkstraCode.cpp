#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const ll N = 1e5+9LL;

vector<pair<ll, ll>> adj[N];
vector<ll> dist(N);

void dijkstra(ll src, ll n){
    ll i;
    for(i = 0; i <= n; i++){
        dist[i] = LLONG_MAX;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[src] = 0;

    pq.push({0, src});

    while(!pq.empty()){
        ll node = pq.top().second;
        ll cost = pq.top().first;

        pq.pop();

        if(cost > dist[node]) continue;

        for(auto &[a, b] : adj[node]){
            if(cost + b < dist[a]) {
                dist[a] = cost + b;
                pq.push({dist[a], a});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ttt = 1, n, i, j, k, l, m, q = 0;
    cin >> ttt;
    while(ttt--){
        cin >> n >> m;
        for(i = 0; i <= n; i++){
            adj[i].clear();
        }
        for(i = 0; i < m; i++){
            ll k1, k2, k3;
            cin >> k1 >> k2 >> k3;
            adj[k1].pb({k2, k3});
            adj[k2].pb({k1, k3});
        }
        dijkstra(1, n);
         cout << "Case " << ++q << ": ";
        if(dist[n] == LLONG_MAX){
            cout << "Impossible";
        }
        else cout << dist[n];
        cout << '\n';

    }

}

/*

Problem: Brush(V) [LightOJ - 1019]


*/

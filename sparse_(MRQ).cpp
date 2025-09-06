#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll N = 1e9;

vector<vector<ll>>sparse;
vector<ll> lg;

void precomputation(vector<ll> &v){
    ll n = v.size();
    //vector<vector<ll>> sparse(n + 1, vector<ll> (log(n) + 1));
    lg.assign(n + 1, 0);
    sparse.assign(n, vector<ll> (log2(n) + 1));
    ll i, j;
    for(i = 0; i < n; ++i) sparse[i][0] = i;
   
    for(j = 1; (1 << j) <= n; ++j){
        for(i = 0; (i + (1 << j) - 1) < n; ++i){
            if(v[sparse[i][j - 1]] < v[sparse[i + (1 << (j - 1))][j - 1]]){
                sparse[i][j] = sparse[i][j - 1];
            }
            else sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
        }
    }
}
ll MRQ(ll lo, ll hi, vector<ll> &v){
    ll l = hi - lo + 1;
    ll k = log2(l);

    return min(v[sparse[lo][k]], v[sparse[lo + l - (1 << k)][k]]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ttt = 1, n, k, i, j, q = 0, m;
    cin >> ttt;
    while(ttt--){
        cin >> n >> q;
        vector<ll> v(n);
        for(auto &it : v) cin >> it;
        precomputation(v);

        while(q--){
            ll l, r;
            cin >> l >> r;
            cout << MRQ(l, r, v) << '\n';
        }
    }
}

/*


*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll N = 1e5+7LL;

vector<ll> seg(4 * N), v;

void build(ll indx, ll lo, ll hi){
    if(lo == hi){
        seg[indx] = v[lo];
        return;
    }
    ll mid = (lo + hi) / 2;
    build(2 * indx + 1, lo, mid);
    build(2 * indx + 2, mid + 1, hi);

    seg[indx] = seg[2 * indx + 1] + seg[2 * indx + 2];
}

void update(ll indx, ll lo, ll hi, ll pos, ll val){
    if(lo == hi){
        seg[indx] = val;
        return;
    }
    ll mid = (lo + hi) / 2;
    if(pos <= mid)
        update(2 * indx + 1, lo, mid, pos, val);
    else
        update(2 * indx + 2, mid + 1, hi, pos, val);

    seg[indx] = seg[2 * indx + 1] + seg[2 * indx + 2];
}

ll query(ll indx, ll lo, ll hi, ll l, ll r){
    if(lo >= l && hi <= r) return seg[indx];
    if(l > hi || r < lo) return 0;

    ll mid = (lo + hi) / 2;
    return query(2 * indx + 1, lo, mid, l, r) + query(2 * indx + 2, mid + 1, hi, l, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ttt = 1, n, i, k, j, q;
    //cin >> ttt;
    while(ttt--){
        cin >> n >> q;
        v.resize(n);
        for(auto &it : v){
            cin >> it;
        }
        build(0, 0, n - 1);

        while(q--){
            ll a, b, c;
            cin >> a >> b >> c;
            if(a == 1){
                update(0, 0, n - 1, b, c);
            }
            else{
                cout << query(0, 0, n - 1, b, c - 1) << '\n';
            }
        }
    }
}

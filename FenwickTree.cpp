#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e6+9LL;
ll fen[N], n;

void add(ll i, ll val) {
    while (i <= n) {
        fen[i] += val;
        i += (i & (-i));
    }
}

ll sum(ll i) {
    ll sum = 0;
    while (i > 0) {
        sum += fen[i];
        i -= (i & (-i));
    }
    return sum;
}

ll rsum(ll l, ll r) {
    return sum(r) - sum(l - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ttt, i, j, m, q;
    cin >> ttt;
    ll caseNum = 0;

    while (ttt--) {
        cin >> n >> q;
        fill(fen, fen + n + 1, 0);
        vector<ll> v(n);

        for (i = 0; i < n; ++i) {
            cin >> v[i];
            add(i + 1, v[i]);
        }

        caseNum++;
        cout << "Case " << caseNum << ":\n";

        while (q--) {
            cin >> m;
            if (m == 1) {
                ll x;
                cin >> x;
                cout << v[x] << '\n';
                add(x + 1, -v[x]);
                v[x] = 0;
            } else if (m == 2) {
                ll indx, val;
                cin >> indx >> val;
                add(indx + 1, val);
                v[indx] += val;
            } else {
                ll l, r;
                cin >> l >> r;
                cout << rsum(l + 1, r + 1) << '\n';
            }
        }
    }
    return 0;
}


//H - Curious Robin Hood LightOJ - 1112

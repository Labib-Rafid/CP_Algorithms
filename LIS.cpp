//BINARY SEARCH WITH PATIENCE SORTING -> nlog(n) technique

#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const ll N = 1e5+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ttt = 1, i, j, k, n, m, q;
    //cin >> ttt;
    while (ttt--){
        cin >> n;
        vector<ll> v(n), ans;
        for(auto &it : v) cin >> it;

        ans.pb(v[0]);
        for(i = 1; i < n; ++i){
            if(v[i] > ans.back()) ans.pb(v[i]);
            else{
                ll lb = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
                ans[lb] = v[i];
            }
        }
        cout << ans.size();
    }
    return 0;
}

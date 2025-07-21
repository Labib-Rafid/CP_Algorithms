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
        string s1, s2;
        cin >> s1 >> s2;
        n = s1.size(), m = s2.size();

        vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));

        for(i = 0; i <= n; ++i){
            for(j = 0; j <= m; ++j){
                if(j == 0) dp[i][j] = i;
                else if(i == 0) dp[i][j] = j;
                else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else{
                    if(i > 0 && j > 0) dp[i][j] = min({dp[i- 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        cout << dp[n][m];
    }
    return 0;
}

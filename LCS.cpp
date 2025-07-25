//Longest Common Sequence between two Strings

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

        vector<vector<ll>> dp(n + 1, vector<ll> (m + 1));

        for(i = 0; i <= n; ++i){
            for(j = 0; j <= m; ++j){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // LCS Length
        cout << dp[n][m];
        
        //Printing LCS
        i = n, j = m;
        vector<char> ans;
        while(i != 0 || j != 0){
            if(dp[i][j] == dp[i][j - 1]) j--;
            else if(dp[i][j] == dp[i - 1][j]) i--;
            else{
                ans.pb(s1[i - 1]);
                i--;
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        for(auto it : ans) cout << it;

    }
    return 0;
}

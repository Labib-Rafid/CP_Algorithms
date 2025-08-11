#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

string s = "aeiou";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ttt = 1, n, i, k, j, q = 0, m;
    //cin >> ttt;
    while(ttt--){
        string s1, s2;
        cin >> s1 >> s2;

        n = s1.size();  m = s2.size();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1));

        for(i = 0; i <= n; ++i){
            for(j = 0; j <= m; ++j){
                bool f = 0, f2 = 0;
                if(i == 0 || j == 0) dp[i][j] = max(i, j);
                else if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else{
                    if(dp[i - 1][j - 1] < dp[i - 1][j] && dp[i - 1][j - 1] < dp[i][j - 1]){

                        for(ll kk = 0; kk < s.size(); ++kk){
                            if(s1[i - 1] == s[kk]) f = 1;
                        }
                        for(ll kk = 0; kk < s.size(); ++kk){
                            if(s2[j - 1] == s[kk]) f2 = 1;
                        }
                        if(f && f2) dp[i][j] = dp[i - 1][j - 1] + 0.5;
                        else if(!f && !f2){
                            dp[i][j] =  dp[i - 1][j - 1] + 1;
                        }
                        else dp[i][j] = dp[i - 1][j - 1] + 2;
                    }
                    else if(dp[i - 1][j] < dp[i - 1][j - 1] || dp[i][j - 1] < dp[i - 1][j - 1]){
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    else{
                        for(ll kk = 0; kk < s.size(); ++kk){
                            if(s1[i - 1] == s[kk]) f = 1;
                        }
                        for(ll kk = 0; kk < s.size(); ++kk){
                            if(s2[j - 1] == s[kk]) f2 = 1;
                        }
                        if(f && f2){
                            dp[i][j] = dp[i - 1][j - 1] + 0.5;
                        }
                        else{
                            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                        }
                    }
                }
            }
        }
            cout << dp[n][m] << '\n';

            ll i = n, j = m;
            while (i > 0 || j > 0){
                bool f = 0, f2 = 0;
                for (ll kk = 0; kk < s.size(); ++kk){
                if (i > 0 && s1[i - 1] == s[kk]) f = 1;
                }
                for (ll kk = 0; kk < s.size(); ++kk){
                    if (j > 0 && s2[j - 1] == s[kk]) f2 = 1;
                }

                if(i > 0 && j > 0 && s1[i - 1] == s2[j - 1]){
                    i--; j--;
                }
                else if(i > 0 && j > 0){
                    double replaceCost;
                    if (f && f2) replaceCost = 0.5;
                    else if (!f && !f2) replaceCost = 1.0;
                    else replaceCost = 2.0;

                    if(abs(dp[i][j] - (dp[i - 1][j - 1] + replaceCost)) < 1e-9) {
                        cout << "Replace " << s1[i - 1] << " with " << s2[j - 1] << "\n";
                        i--; j--;
                    }
                    else if (abs(dp[i][j] - (dp[i - 1][j] + 1)) < 1e-9) {
                        cout << "Delete " << s1[i - 1] << "\n";
                        i--;
                    }
                    else if(abs(dp[i][j] - (dp[i][j - 1] + 1)) < 1e-9) {
                        cout << "Insert " << s2[j - 1] << "\n";
                        j--;
                    }
                }
                else if(i > 0){
                    cout << "Delete " << s1[i - 1] << "\n";
                    i--;
                }
                else if (j > 0){
                    cout << "Insert " << s2[j - 1] << "\n";
                    j--;
                }
            }

    }
}


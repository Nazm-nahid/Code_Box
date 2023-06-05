#include<bits/stdc++.h>

using namespace std;

bool dp[1000][1000],dp1[1000][1000];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
            string s[1000];
            int n;
            cin>>n;
            for(int i=0;i<n;i++)
            {
                cin>>s[i];
            }

            for(int i=n-1;i>=0;i--)
                for (int j=n-1;j>=0;j--)
                    if(s[i][j]=='#') dp[i][j]=false;
                    else if(i==n-1 && s[i][j]=='#') dp[i][j]=false;
                        else if(i==n-1 && s[i][j]=='.') dp[i][j]=true;
                            else dp[i][j]=dp[i+1][j];

            for(int i=n-1;i>=0;i--)
                for (int j=n-1;j>=0;j--)
                    if(s[i][j]=='#') dp1[i][j]=false;
                    else if(j==n-1 && s[i][j]=='#') dp1[i][j]=false;
                        else if(j==n-1 && s[i][j]=='.') dp1[i][j]=true;
                            else dp1[i][j]=dp1[i][j+1];

            int ans=0;

            for(int i=n-1;i>=0;i--)
                for (int j=n-1;j>=0;j--)
                    if(dp[i][j]==dp1[i][j] && dp[i][j]==true) ans++;

            cout<<ans<<endl;

            for(int i=n-1;i>=0;i--)
                for (int j=n-1;j>=0;j--)
                {
                    dp[i][j]= false;
                    dp1[i][j]=false;
                }
    }

    return 0;
}

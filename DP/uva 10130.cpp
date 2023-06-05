#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int cost[1000],w[10000],dp[1005][35],ans[35];

int cap,n;

int dpi(int i,int wt)
{
    int nile_lav,na_nile_lav;
    if (i==n) return 0;
    if(dp[i][wt]!=-1) return dp[i][wt];
    else
    {

            if((wt+w[i])<=cap)
        {

            nile_lav=cost[i]+dpi(i+1,wt+w[i]); // lav= ei taka+ ager lav
        }
        else nile_lav=0;

        na_nile_lav = dpi(i+1,wt); //lav = ager lav

        dp[i][wt]=max(nile_lav,na_nile_lav);
        return dp[i][wt];
    }

}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>cost[i]>>w[i];
    }
    int sum=0;
    for(int i=1;i<=30;i++)
    {
        for(int j=0;j<=n;j++)
            for(int k=0;k<=31;k++)
                dp[j][k]=-1;
                cap=i;
        dpi(0,0);
        ans[i]=dp[0][0];
    }
    int g,a; cin>>g;
    for(int i=0;i<g;i++)
    {
        cin>>a;
        sum+=ans[a];
    }
    cout<<sum<<endl;
    }


}


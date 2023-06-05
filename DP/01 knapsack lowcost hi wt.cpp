#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int cost[1000],w[10000],dp[105][10005];

int cap,n;

int dpi(int i,int wt)
{
    int nile_lav=INT_MAX,na_nile_lav=INT_MAX;
    if (i>=n) return 0;
    if(dp[i][wt]!=INT_MAX) return dp[i][wt];
    else
    {

            if((wt+cost[i+1])<=10000 && i!=n)
        {

            int res=dpi(i+1,wt+cost[i+1]);
             if(w[i]+res<=cap)
            nile_lav=w[i]+res; // lav= ei taka+ ager lav
        }

        na_nile_lav = dpi(i+1,wt); //lav = ager lav
        if(na_nile_lav==0)
            na_nile_lav=INT_MAX;

        dp[i][wt]=min(nile_lav,na_nile_lav);
        return dp[i][wt];
    }

}

int main()
{
    for(int i=0;i<=103;i++)
        for(int j=0;j<10003;j++)
                    dp[i][j]=INT_MAX;
    cin>>n>>cap;
    for(int i=0;i<n;i++)
    {
        cin>>cost[i]>>w[i];
    }
    dpi(0,cost[0]);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<15;j++)
            if(dp[i][j]!=INT_MAX) cout<<dp[i][j]<<" ";
        else cout<<"0 ";
        cout<<endl;
    }

    cout<<dp[0][0]<<endl;

}

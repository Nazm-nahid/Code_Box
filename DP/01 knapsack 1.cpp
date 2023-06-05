#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int w[1005],val[1005],dp[1005][10005];

int cap,n;

int dpi(int i,int v)
{
    int nile_lav,na_nile_lav;
    if (i==n) return 0;
    if(dp[i][v]!=-1) return dp[i][v];
    else
    {

            if((v+val[i])<=cap)
        {

            nile_lav=w[i]+dpi(i+1,v+val[i]); // lav= ei val+ ager lav
        }
        else nile_lav=0;

        na_nile_lav = dpi(i+1,v); //lav = ager lav

        dp[i][v]=max(nile_lav,na_nile_lav);
        return dp[i][v];
    }

}

int main()
{
    for(int i=0;i<=1003;i++)
        for(int j=0;j<10003;j++)
                    dp[i][j]=-1;
    cin>>n>>cap;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>val[i];
    }
    dpi(0,0);

    cout<<dp[0][0]<<endl;

}

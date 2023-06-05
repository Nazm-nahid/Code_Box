#include<bits/stdc++.h>

using namespace std;

int dp[13][13][13];
int n,k,a[10000],ans=0;



int coin(int i,int prev,int cnt)
{

    if(i>k) return 0;
    if(cnt==n) return 1;
    if(dp[i][prev][cnt]!=-1) return dp[i][prev][cnt];
    int ap=0,bp=0;
    if(a[i]-prev<=2)
        ap=coin( i+1 , a[i],cnt ++);
    bp=coin( i+1 , a[i],cnt ++);
    dp[i][prev][cnt]=ap*2 + bp;
    return dp[i][prev][cnt];
}

int main()
{

    int t; cin>>t;

    while(t--)
    {
        memset(dp,-1,sizeof dp);
        ans=0;
        cin>>k>>n;
        for(int j=1;j<=k;j++) cin>>a[j];

        cout<<coin(1,0,0)<<endl;
    }

    return 0;
}



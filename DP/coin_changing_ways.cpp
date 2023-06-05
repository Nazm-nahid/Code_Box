#include<bits/stdc++.h>

using namespace std;

int dp[100000];


int coin(int n,int k,int a[])
{
    memset(dp,1000007,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=k;j++)  //k is no. of coin
        {
             if(a[j]<=i)
                {
                    if( dp[i-a[j]]!=1000007)
                    dp[i]=min(dp[i],dp[i-a[j]] +1);
                }
         }
    }


    return dp[n];
}

int main()
{

        int n,k,a[10000],b[100000];
        cin>>n>>k; //k is no. of coin
        for(int j=1;j<=k;j++) cin>>a[j];

        cout<<coin(n,k,a)<<endl;
    return 0;
}


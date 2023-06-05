#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[205][205];

ll a[205][205],n;

ll call(int i,int j)
{

    if(i>=0 && i<(2*n-1) && j>=0 && j<i+1)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];

            ll ret1,ret2;
            ret1=call(i+1,j)+a[i][j];
        if(i<n-1)    ret2=call(i+1,j+1)+a[i][j];
        else         ret2=call(i+1,j-1)+a[i][j];
            dp[i][j]=max(ret1,ret2);
            return dp[i][j];//=bp;

    }
    else return dp[i][j]=0;

}

int main()
{
    int t,k=0;cin>>t;
    while(t--)
    {
        k++;
        for(int i=0;i<=201;i++)
            for(int j=0;j<=201;j++)
        {
            a[i][j]=0;
            dp[i][j]=-1;
        }

        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<i+1;j++)
            cin>>a[i][j];
        for(int i=n,k=n-1;i<2*n;k--,i++)
            for(int j=0;j<k;j++)
            cin>>a[i][j];
            call(0,0);
            cout<<"Case "<<k<<": "<<dp[0][0]<<endl;

        }


    }


#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int cost[1000],w[10000],dp[10005];

int cap,n,nap=10000;

void dpi()
{
    for(int i=0;i<n;i++)
    {
        for(int j=nap;j>=0;j--)
    {
       if(cost[i]<=j)
                {
                    if( dp[j-cost[i]]!=INT_MAX)
                    dp[j]=min(dp[j],dp[j-cost[i]] +w[i]);
                   // if(dp[j]!=INT_MAX)
                   // cout<<dp[j]<<"ok"<<j<<endl;
                   // else dp[j]=
                }
    }// cout<<"___________________________________________________________________________"<<i<<endl;
    }

        return;// dp[cap];
}

int main()
{

        for(int j=0;j<10003;j++)
                    dp[j]=INT_MAX;
                    dp[0]=0;
    cin>>n>>cap;
    for(int i=0;i<n;i++)
    {
        cin>>cost[i]>>w[i];
    }
    dpi();

    //int mn=INT_MAX;if(dp[kl]!=INT_MAX)cout<<dp[kl]<<"ok"<<kl<<endl; cout<<endl;//
    int indx=0;
    for(int kl=nap;kl>=0;kl--){ if(dp[kl]<=cap) {indx=kl; break;}}
    cout<<indx<<endl;

}



#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int cost[1000],w[10000],dp[1005][1005];

string a,b;
int n,m;

int dpi(int i,int j)
{

    if(i==n || j== m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i]==b[j])
        return dp[i][j]=1+dpi(i+1,j+1);

    else return dp[i][j]=max(dpi(i+1,j),dpi(i,j+1));
}

void clearr(int l,int p)
{
    for(int i=0;i<=l;i++)
        for(int j=0;j<=p;j++) dp[i][j]=-1;
}

int main()
{


                    int t;
                    cin>>t;
                    while(t--)
                    {
                        cin>>a>>b;
                        n=a.size();
                        m=b.size();
                        clearr(n+2,m+2);
                        cout<<dpi(0,0)<<endl;
                    }



}

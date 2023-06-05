#include<bits/stdc++.h>


using namespace std;


int dp[2000][2000],n,m;
 string s,sk;

int dpi(int i,int j)
{
    if(i==n) return m-j;
    if(j==m) return n-i;
    if(dp[i][j]) return dp[i][j];
    int ret,ret1,ret2;

    if(s[i]==sk[j])
        ret=0+dpi(i+1,j+1);
    else ret=1+dpi(i+1,j+1);

     ret1= 1+ dpi(i,j+1);
     ret2= 1+ dpi(i+1,j);

    return dp[i][j]=min({ret,ret1,ret2});
}


int main()
{


    cin>>s>>sk;
    n=s.size(); m=sk.size();
    cout<<dpi(0,0)<<endl;
}

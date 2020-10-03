// BISMILLAHIR_RAHMANIR_RAHIM
#include <bits/stdc++.h>
#define ll long long
#define sn1(a) scanf("%lld",&a)
#define sn2(a,b) scanf("%lld %lld",&a,&b)
#define pn1(a) printf("%lld\n", a)
#define pn2(a,b) printf("%lld %lld\n",a,b)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define PB push_back
#define F first
#define S second
#define MOD 1000000007

using namespace std;
ll bgm(ll a, ll b , ll c)
{
    ll x,y;
    if(b==0)
        return 1;
    else if(b%2==0)
    {
       y=bgm(a,b/2 , c);
       return (y*y)%c;
    }
    else
    {
        x=a%c;
        return (x*bgm(a,b-1,c))%c;
    }
}


int main()
{
    ll N,m,k,l,r,i,ans,T,j,result,B,P,M;


    //(a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD

    while(cin>>B>>P>>M)
    {
         cout<<bgm(B,P,M)<<endl;
    }

	return 0;
}
// ALHAMDULLIAH


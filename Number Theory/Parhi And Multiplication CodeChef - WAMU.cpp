// BISMILLAHIR_RAHMANIR_RAHIM
#include <bits/stdc++.h>
#define ll long long
#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)
#define pf1(a) printf("%lld\n", a)
#define pf2(a,b) printf("%lld %lld\n",a,b)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define PB push_back
#define F first
#define S second
#define MOD 1000000007

using namespace std;


ll ar[1000000],m;
ll sum[100000];
int main()
{
    ll N,m,k,l,r,i,ans,T,j,result;

    cin>>T;
    //(a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD

    FOR(i,T)
    {
        cin>>N;
        result=1;
        FOR(j,N)
        {
            cin>>ar[j];
            ar[j]=ar[j]%MOD;

            result=result*ar[j];
            result=result%MOD;
        }result=result%MOD;
         cout<<result<<endl;
    }

	return 0;
}
// ALHAMDULLIAH

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

using namespace std;


ll ar[1000000],m;
ll sum[100000];
int main()
{
    ll N,m,k,l,r,i,ans;

    cin>>N;
    sum[-1]=0;
    FOR(i,N)
    {
        cin>>ar[i];
        sum[i]=sum[i-1]+ar[i];
    }
    cin>>m;
    FOR(i,m)
    {
        cin>>l>>r;
        ans=sum[r]-sum[l-1];
        cout<<ans<<endl;
    }
	return 0;
}
// ALHAMDULLIAH


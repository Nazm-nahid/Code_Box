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

int main()
{
    ll N,m,k,l,r,i,ans,cnt=0,a,j;
     FOR(j,10)
     {
       int  ar[42]={0};
         FOR(i,10)
    {
cin>>a;
        ar[a%42]=1;

    }
    FOR(i,42)
    {
        if(ar[i])
            cnt++;
    }
     cout<<cnt<<endl;
    cnt=0;
     }

	return 0;
}
// ALHAMDULLIAH


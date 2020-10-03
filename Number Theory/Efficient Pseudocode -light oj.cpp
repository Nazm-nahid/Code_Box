#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f(n) for(ll i=0;i<n;i++)
#define ina for(ll i=0;i<n;i++)cin>>a[i];
#define all(v) v.begin(),v.end()
#define YES printf("YES\n")
#define NO printf("NO\n")
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
long long bigmod/* (a^p)%m */ ( long long a, long long p, long long m ){long long res = 1;long long x = a;while ( p ){if ( p & 1 ){res = ( res * x ) % m;}x = ( x * x ) % m;p = p >> 1;}return res;}
long long modInverse(long long a, long long m) { ll m0 = m; ll y = 0, x = 1; if (m == 1) return 0; while (a > 1) { ll q = a / m; ll t = m; m = a % m, a = t; t = y; y = x - q * y; x = t; } if (x < 0) x += m0; return x; }
const long long MAX_SIZE = 1000001; vector<long long >isprime(MAX_SIZE , true); vector<long long >prime; vector<long long >SPF(MAX_SIZE); void manipulated_seive(int N) { isprime[0] = isprime[1] = false ; for (long long int i=2; i<N ; i++) { if (isprime[i]) { prime.push_back(i); SPF[i] = i; } for (long long int j=0; j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i]; j++) { isprime[i*prime[j]]=false; SPF[i*prime[j]] = prime[j] ; } } }
/*speedup
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
//Pattern? OEIS



int main()
{
    //fastio;
    manipulated_seive(1e5);

        ll t,cs=0; cin>>t;
        while(t--)
        {
           ll n,m;
           scanf("%lld%lld",&n,&m);
           ll nn=n;
           ll ans=1;
           ll mod=1e9+7;
           for (int i=0; i<prime.size() && prime[i]*prime[i] <= nn ; i++)
           {
               //cout<<prime[i]<<endl;
               ll cnt=0;
               if(n%prime[i]==0)
               {
                   while(n%prime[i]==0)
                       {
                           n/=prime[i];
                           cnt++;
                       }

                    ans*=( ((bigmod(prime[i],(cnt*m)+1,mod)-1 +mod)%mod) * ((modInverse((prime[i]-1),mod)+mod )%mod) )%mod;
                    ans%=mod;
               }


           }

           if(n>1) ans*=( ((bigmod(n,m+1,mod)-1 + mod)%mod) * ((modInverse((n-1),mod)+mod )%mod) )%mod;
               ans%=mod;

            printf("Case %lld: %lld\n",++cs,ans);
           //cout<<ans<<endl;
        }

    return 0;
}


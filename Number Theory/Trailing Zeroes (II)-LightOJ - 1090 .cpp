#include<bits/stdc++.h>
#define ll long long
#define llu unsigned long long
#define pb push_back
#define f(n) for(ll i=0;i<n;i++)
#define ina for(ll i=0;i<n;i++)cin>>a[i];
#define all(v) v.begin(),v.end()
#define YES printf("YES\n")
#define NO printf("NO\n")
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define finout freopen("input.cpp","r",stdin); freopen("output.cpp","w",stdout);
using namespace std;
//long long bigmod/* (a^p)%m */ ( long long a, long long p, long long m ){long long res = 1;long long x = a;while ( p ){if ( p & 1 ){res = ( res * x ) % m;}x = ( x * x ) % m;p = p >> 1;}return res;}
//ll modInverse(ll a, ll m) { ll m0 = m; ll y = 0, x = 1; if (m == 1) return 0; while (a > 1) { ll q = a / m; ll t = m; m = a % m, a = t; t = y; y = x - q * y; x = t; } if (x < 0) x += m0; return x; }
//call manipulated_seive(N) and get prime in prime vector
//const long long MAX_SIZE = 1000006LL; vector<long long >isprime(MAX_SIZE , true); vector<long long >prime; vector<long long >SPF(MAX_SIZE); void manipulated_seive(int N) { isprime[0] = isprime[1] = false ; for (long long int i=2; i<N ; i++) { if (isprime[i]) { prime.push_back(i); SPF[i] = i; } for (long long int j=0; j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i]; j++) { isprime[i*prime[j]]=false; SPF[i*prime[j]] = prime[j] ; } } }
//ll phi[5000001];bool mark[5000001];void sievephi(ll n){ll i,j;for(ll i=1;i<=n;i++) phi[i]=i;mark[1]=true;for(ll i=2;i<=n;i++)if(!mark[i]){for(ll j=i;j<=n;j+=i){mark[j]=true;phi[j]=phi[j]/i*(i-1);}}}

/*speedup
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
// vule geli coilbi na dada cout << fixed << setprecision(6) << pi <<" "<<npi<<endl;
//Pattern? OEIS
// prime factorize?? think about 2

ll a[1000006];
ll b[1000006];

int number_of(int n,int f)
{
            int c=0;
            while(n)
                {
                     n/=f;
                     c+=n;
                }
            return c;
}

int number_of_prime(int n,int f)
{
            int c=0;
            while(n%f==0)
                {
                     n/=f;
                     c++;
                }
            return c;
}

void solve()
{
    ll n,r,p,q; scanf("%lld %lld %lld %lld",&n ,&r ,&p ,&q);
    ll _5= a[n]-a[r]-a[n-r];
    ll _2= b[n]-b[r]-b[n-r];

    _5+= q*number_of_prime(p,5);
    _2+= q*number_of_prime(p,2);

    printf("%lld\n",min(_5,_2));

}

int main()
{
        for(int i=1;i<=1000005;i++)
        {
            a[i] = number_of(i,5);
            b[i] = number_of(i,2);
        }


        ll t,cs=0; scanf("%lld",&t);
        while(t--)
        {
            printf("Case %lld: ",++cs);
            solve();
        }


    return 0;
}

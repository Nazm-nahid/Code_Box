#include<bits/stdc++.h>
#define ll long long
#define llu unsigned long long
#define pb push_back
#define f(n) for(ll i=0;i<n;i++)
#define ina for(ll i=0;i<n;i++)cin>>a[i];
#define all(v) v.begin(),v.end()
#define YES printf("YES\n")
#define NO printf("NO\n")
#define IsComp(n)  (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define finout freopen("input.cpp","r",stdin); freopen("output.cpp","w",stdout);
using namespace std;
//ll pow(ll a,ll b) { ll ret=1; for(ll i=0;i<b;i++) ret*=a; return ret;}
//long long bigmod/* (a^p)%m */ ( long long a, long long p, long long m ){long long res = 1;long long x = a;while ( p ){if ( p & 1 ){res = ( res * x ) % m;}x = ( x * x ) % m;p = p >> 1;}return res;}
//ll modInverse(ll a, ll m) { ll m0 = m; ll y = 0, x = 1; if (m == 1) return 0; while (a > 1) { ll q = a / m; ll t = m; m = a % m, a = t; t = y; y = x - q * y; x = t; } if (x < 0) x += m0; return x; }
//call manipulated_seive(N) and get prime in prime vector
const long long MAX_SIZE = 1000006; vector<long long >isprime(MAX_SIZE , true); vector<long long >prime; vector<long long >SPF(MAX_SIZE); void manipulated_seive(int N) { isprime[0] = isprime[1] = false ; for (long long int i=2; i<N ; i++) { if (isprime[i]) { prime.push_back(i); SPF[i] = i; } for (long long int j=0; j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i]; j++) { isprime[i*prime[j]]=false; SPF[i*prime[j]] = prime[j] ; } } }
//bitwise sieve //size of prime array = sz
//const int MAX = 100000000;const int LMT = 10000;int _c[(MAX>>6)+1];ll  prime[5761482];ll sz=0;void bitwise_sieve(){for (int i = 3; i <= LMT; i += 2)if (!IsComp(i))for (int j = i*i; j <= MAX; j += i+i) SetComp(j);prime[sz++]=2;for (int i=3; i <= MAX; i += 2)if (!IsComp(i))prime[sz++]=i;}
//ll phi[5000001];bool mark[5000001];void sievephi(ll n){ll i,j;for(ll i=1;i<=n;i++) phi[i]=i;mark[1]=true;for(ll i=2;i<=n;i++)if(!mark[i]){for(ll j=i;j<=n;j+=i){mark[j]=true;phi[j]=phi[j]/i*(i-1);}}}

/*speedup
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
// vule geli coilbi na dada cout << fixed << setprecision(6) << pi <<" "<<npi<<endl;
//Pattern? OEIS
// prime factorize?? think about 2


//Miller Rabin Primality check
ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b)
    {
        if (b & 1) x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = mulmod(ret, x, MOD);
        x = mulmod(x, x, MOD);
        n >>= 1;
    }
    return ret % MOD;
}

bool isPrime(ll n)
{
    if(n == 2 || n == 3) return true;
    if(n == 1 || !(n & 1)) return false;
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }

    int a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for(int i = 0; i < 9; i++)
    {
        if(n == a[i]) return true;
        bool comp = fastPow(a[i], d, n) != 1;
        if(comp) for(int j = 0; j < s; j++)
            {
                ll fp = fastPow(a[i], (1LL << (ll)j)*d, n);
                if (fp == n - 1)
                {
                    comp = false;
                    break;
                }
            }
        if(comp) return false;
    }
    return true;
}
//__________


void solve()
{
    ll n; cin>>n;
     ll x=n ,nod=1;
    for(int i=0;i<prime.size() && prime[i]*prime[i]*prime[i]<=x;i++)
    {
        if(n%prime[i]==0)
        {
            ll c=0;
            while(n%prime[i]==0)
            {
                c++;
                n/=prime[i];
            }
            nod*=(c+1);
        }
    }

    if(n>1)
    {
        ll sq =sqrtl(n) ;
        if(isPrime(n)) nod*=2LL;
        else if(sq*sq == n) nod*=3LL;
        else nod*=4LL;
    }
    cout<<nod<<endl;
}

int main()
{
        manipulated_seive(1000005);
        ll t; cin>>t;
        while(t--)
         solve();

    return 0;
}


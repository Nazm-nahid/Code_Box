#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

bool prime[10000015];

vector<ll>cake;
ll chips=0;
ll neka=10000005;
void SieveOfEratosthenes()
{
    memset (prime, false, sizeof (prime));

    for (ll i=2;i<neka;i++)
    {
        if (! prime [i])
        {
            cake.pb(i);
                    for (ll j = 2*i; j <neka; j+= i)
                {
                    prime [j] = true;
                }
                //}

               // else break;
        }
        if(cake.size()>1000005) break;
    }
}


ll primefactor(ll biscuit)
{
    ll ans=1;
    for(int cha=0;cha< cake.size()&& cake[cha]<=biscuit;cha++)
        {
            if(biscuit%cake[cha]==0)
            {
                    ll chumuk=0;
                 while( biscuit%cake[cha]==0)
                 {
                    chumuk++;
                   // cout<<cake[cha]<<" * ";
                    biscuit/=cake[cha];
                 }
                 ans*=(2*chumuk+1);
            }

        }
        if(biscuit>1) ans*=3;
       // cout<<biscuit<<endl;

        return ans/2 +1;

}

int main()
{
    SieveOfEratosthenes();
    //cout<<"o";
    //cout<<cake.size()<<endl;
    ll t,cs=0; cin>>t;
    while(t--)
    {
        ll n; cin>>n;

        cout<<"Case "<<++cs<<": "<<primefactor(n)<<endl;

    }

    return 0;
}

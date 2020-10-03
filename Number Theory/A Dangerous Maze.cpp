#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f(n) for(ll i=0;i<n;i++)
#define ina for(ll i=0;i<n;i++)cin>>a[i];
#define all(v) v.begin(),v.end()
#define YES printf("YES\n")
#define NO printf("NO\n")
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
/*speedup
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
using namespace std;

vector<int>v,a;
map<int,int>mp;

int main()
{
    fastio;


            int n,x; cin>>n;
            for(int i=0;i<n;i++)
            {
               cin>>x;
               v.pb(x);
            }
            for(int i=0;i<n;i++)
            {
               cin>>x;
                //a.pb(x);
                mp[x]=n-i-1;
            }
             reverse(all(v));
             cout<<"ok"<<endl;
            ll c=0;
            for(int i=0;i<n;i++)
            {
               x=v[i];
               //if(mp[x]>i){c++; }//cout<<i<<endl;}
               cout<<mp[x]<<" ";
            }
        cout<<c<<endl;

    return 0;
}



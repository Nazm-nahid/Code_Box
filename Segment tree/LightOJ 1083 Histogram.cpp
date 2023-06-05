#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

ll a[200000],ar[500000];
ll mx=-10000;
pair<ll,ll> build(ll l,ll r,ll node)
{

    if(l==r)
    {
        ar[node]=a[l];
        mx=max(mx,ar[node]);
        return {ar[node],1};
    }

    ll mid=(l+r)/2;
    ll left=2*node;
    ll right=(2*node)+1;

   pair<ll,ll> a= build(l,mid,left);
   pair<ll,ll> b= build(mid,r,right);
   ar[node]=min(a.first,b.first);
   ll pp=a.second+b.second;
   mx=max(mx, ar[node]*pp);
   return {ar[node],pp};
}

ll query(ll l,ll r,ll node,ll lmtl,ll lmtr)
{
    if(r<lmtl || l>lmtr) return 10000000;
    if(lmtl<=l && r<=lmtr) return ar[node];
    ll mid=(l+r)/2;
    ll a =query(l,mid,2*node,lmtl,lmtr);
    ll b =query(mid+1,r,(2*node)+1,lmtl,lmtr);
   return min(a,b);
}


int main()
{
   ll t,cs=0,ap,b,n,q;scanf("%lld",&t);
   while(t--)
   {
       printf("Case %lld: ",++cs);
        scanf("%lld",&n,&q);
       for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
       build(1,n,1);
        cout<<"ok"<<endl;
       for(int i=1;i<n;i++)
       {
           mx=max(mx,query(1,n,1,i,i+1)*2);
       }
        printf("%lld\n",mx);
    for(ll i=1;i<=4*n;i++) ar[i]=0;
    mx=-1000;
   }
}


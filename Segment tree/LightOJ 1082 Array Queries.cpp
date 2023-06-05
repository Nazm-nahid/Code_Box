#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int a[200000],ar[500000];

int build(int l,int r,int node)
{

    if(l==r)
    {
        return ar[node]=a[l];
    }

    int mid=(l+r)/2;
    int left=2*node;
    int right=(2*node)+1;

   int a= build(l,mid,left);
   int b= build(mid+1,r,right);
   return ar[node]=min(a,b);
}

int query(int l,int r,int node,int lmtl,int lmtr)
{
    if(r<lmtl || l>lmtr) return 10000000;
    if(lmtl<=l && r<=lmtr) return ar[node];
    int mid=(l+r)/2;
    int a =query(l,mid,2*node,lmtl,lmtr);
    int b =query(mid+1,r,(2*node)+1,lmtl,lmtr);
   return min(a,b);
}



int main()
{
   int t,cs=0,ap,b,n,q;
   cin>>t;
   while (t--)
   {
       scanf("%d%d",&n,&q);
       for(int i=1;i<=n;i++) scanf("%d",&a[i]);
       build(1,n,1);
       for(int i=0;i<q;i++)
       {
            scanf("%d%d",&ap,&b);
           printf("%d\n",query(1,n,1,ap,b));
       }

   }
}

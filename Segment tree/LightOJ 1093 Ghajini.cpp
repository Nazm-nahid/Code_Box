#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int a[200000],ar[500000],br[500000];

int build_min(int l,int r,int node)
{

    if(l==r)
    {
        return ar[node]=a[l];
    }

    int mid=(l+r)/2;
    int left=2*node;
    int right=(2*node)+1;

   int a= build_min(l,mid,left);
   int b= build_min(mid+1,r,right);
   return ar[node]=min(a,b);
}

int build_max(int l,int r,int node)
{

    if(l==r)
    {
        return br[node]=a[l];
    }

    int mid=(l+r)/2;
    int left=2*node;
    int right=(2*node)+1;

   int a= build_max(l,mid,left);
   int b= build_max(mid+1,r,right);
   return br[node]=max(a,b);
}

int query_min(int l,int r,int node,int lmtl,int lmtr)
{
    if(r<lmtl || l>lmtr) return 10000000;
    if(lmtl<=l && r<=lmtr) return ar[node];
    int mid=(l+r)/2;
    int a =query_min(l,mid,2*node,lmtl,lmtr);
    int b =query_min(mid+1,r,(2*node)+1,lmtl,lmtr);
   return min(a,b);
}
int query_max(int l,int r,int node,int lmtl,int lmtr)
{
    if(r<lmtl || l>lmtr) return -10000000;
    if(lmtl<=l && r<=lmtr) return br[node];
    int mid=(l+r)/2;
    int a =query_max(l,mid,2*node,lmtl,lmtr);
    int b =query_max(mid+1,r,(2*node)+1,lmtl,lmtr);
   return max(a,b);
}



int main()
{
   int t,cs=0,ap,b,n,q;scanf("%d",&t);
   while(t--)
   {
       printf("Case %d: ",++cs);
        scanf("%d%d",&n,&q);
       for(int i=1;i<=n;i++) scanf("%d",&a[i]);
       build_min(1,n,1);
       build_max(1,n,1);
       int mx=INT_MIN;
       for(int kp=0;kp<4*n;kp++) cout<<ar[kp]<<" "; cout<<"kkk"<<endl;
       for(int i=q,j=1;i<=n;i++,j++)
       {
            int kp=query_max(1,n,1,j,i)-query_min(1,n,1,j,i);
            cout<<query_max(1,n,1,j,i)<<" "<<query_min(1,n,1,j,i)<<"ool"<<endl;
            mx=max(kp,mx);
            //cout<<kp<<"ppl"<<endl;

       }
    printf("%d\n",mx);
   }
}


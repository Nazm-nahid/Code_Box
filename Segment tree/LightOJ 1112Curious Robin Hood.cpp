#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int a[200000],ar[500000];

int build(int l,int r,int node)
{

    if(l==r)
    {//cout<<l<<"LLK"<<node<<endl;
        return ar[node]=a[l];
    }

    int mid=(l+r)/2;
    int left=2*node;
    int right=(2*node)+1;

   int a= build(l,mid,left);
   int b= build(mid+1,r,right);
   return ar[node]=a+b;
}

int query(int l,int r,int node,int lmtl,int lmtr)
{
    if(r<lmtl || l>lmtr) return 0;
    if(lmtl<=l && r<=lmtr) return ar[node];
    int mid=(l+r)/2;
    int a =query(l,mid,2*node,lmtl,lmtr);
    int b =query(mid+1,r,(2*node)+1,lmtl,lmtr);

   return a+b;
}

int update(int l,int r,int node,int point,int value)
{
    if(point<l || point >r) return ar[node];

    if(l== point && r==point) return ar[node]=ar[node]+value;

    int mid=(l+r)/2;
    int a =update(l,mid,2*node,point,value);
    int b =update(mid+1,r,(2*node)+1,point,value);
    return ar[node]=a+b;
}



int main()
{
   int t,cs=0,ap,b,c,n,q;scanf("%d",&t);
   while(t--)
   {
       printf("Case %d:\n",++cs);
        scanf("%d%d",&n,&q);
       for(int i=1;i<=n;i++) scanf("%d",&a[i]);
       build(1,n,1);
       for(int i=0;i<q;i++)
       {
           scanf("%d",&ap);
           if(ap==1)
           {
               scanf("%d",&b);
               update(1,n,1,b+1,-a[b+1]);
               printf("%d\n",a[b+1]);
               a[b+1]=0;
           }
           else if(ap==2)
           {
               scanf("%d%d",&b,&c);
               update(1,n,1,b+1,c);
               a[b+1]+=c;
           }
           else
           {
               scanf("%d%d",&b,&c);
           printf("%d\n",query(1,n,1,b+1,c+1));
           }//for(int kp=0;kp<4*n;kp++) cout<<ar[kp]<<" "; cout<<endl;


       }

   }
}


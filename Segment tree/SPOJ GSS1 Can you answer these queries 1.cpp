#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int a[200000],ar[500000],prevl=0,prevr=0,latai[1000000];

int build(int l,int r,int node)
{

    if(l==r)
    {
        if(a[l]<0) prevr=a[l];
        return ar[node]=a[l];
    }

    int mid=(l+r)/2;
    int left=2*node;
    int right=(2*node)+1;

   int a= build(l,mid,left);
   latai[node]+=prevr;
   prevr=0;
   int b= build(mid+1,r,right);
   latai[node]+=prevr;prevr=0;// 8 1 4 -3 4 5 -2 7 8 cout<<ar[node]<<"ppl"<<endl,
    if(a<0 || b<0)
    {
        if(b<0)
        prevr=b;
        else prevr=a;
        return ar[node]=max({a+b,a,b});
    }

   else
   {
       //cout<<latai[node]<<endl;
       //if(abs(latai[node])>b || abs(latai[node])>a)
       return ar[node]=max({a+b+latai[node],a,b});
       /*else
       {
           ar[node]=max({a+b+prevr,a,b});
           prevr=0;
           return ar[node];
       }*/
   }
}

int query(int l,int r,int node,int lmtl,int lmtr)
{
    if(r<lmtl || l>lmtr) return 0;
    if(lmtl<=l && r<=lmtr) return ar[node];
    int mid=(l+r)/2;
    int a =query(l,mid,2*node,lmtl,lmtr);
    int b =query(mid+1,r,(2*node)+1,lmtl,lmtr);
   return  max({a+b+latai[node],a,b});
}



int main()
{
   int t,cs=0,ap,b,n,q;

        scanf("%d",&n);
       for(int i=1;i<=n;i++) scanf("%d",&a[i]);

       build(1,n,1);//for(int i=1;i<=4*n;i++) cout<<ar[i]<<" "<<latai[i]<<endl;; cout<<endl;
       scanf("%d",&q);
       for(int i=0;i<q;i++)
       {
            scanf("%d%d",&ap,&b);
            if(ap==b) printf("%d\n",a[b]);
            else
            //cout<<"ok"<<endl;
           printf("%d\n",query(1,n,1,ap,b));

       }


}


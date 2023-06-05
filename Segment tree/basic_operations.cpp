#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sum[4000000],val[1000000];

//build your segment tree
void build(ll node,ll l, ll r)
{
    sum[node]=0;
    if(l==r)
    {
        sum[node]=val[l]; //leaf node
        return;
    }

    ll mid= (l+r)/2;

    build(node*2,l,mid); //left
    build(node*2+1,mid+1,r); //right

    sum[node]=sum[node*2] +sum[node*2+1]; // sum=left+ right
}


//point update in segment tree
void update(ll node,ll l, ll r, ll point , ll value)
{
    if(l==r)
    {
        sum[node]=val[l]+ value; //update with value
        return;
    }

    ll mid= (l+r)/2;

    if(point<=mid) update(node*2,l,mid,point,value); //if point<=mid then call left
    else update(node*2+1,mid+1,r,point , value); //else right

    sum[node]=sum[node*2] +sum[node*2+1]; // sum=left+ right
}

//query - sum [l,r]
ll query(ll node,ll l, ll r, ll ql, ll qr)
{
    if(qr< l || r< ql) return 0; // if out of range contribution in sum= 0
    if(ql<= l && r<= qr) return sum[node]; // if range cover l and r contribution in sum= sum[node]


    ll mid= (l+r)/2;

    ll left_sum = query(node*2,l,mid,ql,qr);
    ll right_sum = query(node*2+1,mid+1,r,ql,qr);

    return left_sum +right_sum;
}


// find index where sum k prom beganing
ll kth(ll node,ll l, ll r, ll k , ll left_contribution)
{
    if(l==r)
    {
        return node;
    }

    ll mid= (l+r)/2;

    if(k <= sum[2*node]+ left_contribution)
        kth(node*2,l,mid,k , left_contribution);//left
    else kth(node*2+1,mid+1,r,k, left_contribution+ sum[node*2]); //right

    //if right then we have to add left sum to right

}

int main()
{

    ;
}

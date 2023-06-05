#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int g[200000][13];
ll sz=0,fg=0;
int cnt[200100];
int ses[200100];

void insrt(string a)
{
    int l=a.size();
    int x=0,id;
    for(int i=0;i<l;i++)
    {
        id=a[i]-'0';
        if(g[x][id]==0)
        g[x][id]=++sz;
       // g[x][id]=sz;
        x=g[x][id];
        cnt[x]++;
        if(ses[x]!=0) {fg=1; }
    }
        ses[x]++;
        if(cnt[x]>1) {fg=1; }
}



int main()
{
    ll t,cs=1;cin>>t;
    while(t--)
    {
        fg=0,sz=0;
        for(int i=0 ;i<200000;i++)
            for(int j=0;j<13;j++)
            g[i][j]=0;
        for(int i=0;i<200100;i++){cnt[i]=0; ses[i]=0;}
        ll n,k;cin>>n;
        k=n;

        for(int i=0;i<n;i++)
        {
            string a;cin>>a;

            insrt(a);
        }


        if(fg==0) cout<<"Case "<<cs++<<": YES\n";
        else cout<<"Case "<<cs++<<": NO\n";



    }


}

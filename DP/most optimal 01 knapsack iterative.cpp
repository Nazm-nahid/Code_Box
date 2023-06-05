#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

ll cost[42],w[42];
map<ll,ll>mp,mmp;
vector<ll> banate_parbo,joma;

ll mx=INT_MIN;
ll cap,n;

void dpi()
{
        banate_parbo.pb(0);
        mmp[0]=1;
        int j,i;
        for( i=0;i<n;i++)
        {
            for( j=0;j<banate_parbo.size();j++)
            {
                if( mp[banate_parbo[j] +cost[i]])
                mp[banate_parbo[j] +cost[i] ]= min(mp[banate_parbo[j]]+w[i]  , mp[banate_parbo[j] + cost[i]]);
                else  mp[banate_parbo[j] +cost[i] ]= mp[banate_parbo[j]]+w[i] ;

                joma.pb(banate_parbo[j] +cost[i]);

              //  if(mp[banate_parbo[j] +cost[i] ] <=cap)
                   // mx=max(mx, banate_parbo[j] +cost[i]);
            }
            for(int j=0;j<joma.size();j++) if(!mmp[joma[j] ]){banate_parbo.pb(joma[j]);mmp[joma[j]]=1;} joma.clear();
           sort(banate_parbo.rbegin(),banate_parbo.rend());

        }

        for( j=0;j<banate_parbo.size();j++) {if(mp[banate_parbo[j]]<=cap) mx=max(mx,banate_parbo[j]);}




        return;// dp[cap];
}

int main()
{
    cin>>n>>cap;
    ll i;
    for( i=0;i<n;i++)
    {
        cin>>cost[i]>>w[i];
    }
    dpi();
    cout<<mx<<endl;

}



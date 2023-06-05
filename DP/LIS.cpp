#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

vector<int>dp,a;

int n,x;

void lis(){
    dp.clear();
     for(int i=0;i<n;i++)
        {
            auto k=lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
             if(k==dp.size()) dp.pb(a[i]);
             else dp[k]=a[i];
     }
    }

void lds(){
    dp.clear();
//    reverse(all(a));
     for(int i=0;i<n;i++)
        {
            auto k=lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
             if(k==dp.size()) dp.pb(a[i]);
             else dp[k]=a[i];
     }
    }



int main()
{


                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                        cin>>x;
                        a.pb(x);
                    }
                    lis();
                    cout<<"Longest Increasing Subsequence : "<<endl;
                    for(auto kk: dp) cout<<kk<<" ";
                    cout<<endl;
                    lds();
                    cout<<"Longest Decreasing Subsequence : "<<endl;
                    for(auto kk: dp) cout<<kk<<" ";
                    cout<<endl;

}


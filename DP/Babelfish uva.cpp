#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
map<string,string>mp;

string a;

int main()
{
                    while(1)
                    {
                        getline(cin,a);
                        if(a.size()==0) break;
                        string b,c;
                        for(auto x:a)
                        {
                            if(x==' ') break;
                            c+=x;

                        }
                        bool fg=false;
                        for(auto x:a)
                        {
                            if(fg)
                            b+=x;
                            if(x==' ') fg=true;
                        }
                        mp[b]=c;

                    }
                    while(cin>>a)
                    {
                        if(mp[a].size()==0){cout<<"eh"<<endl; continue;}
                        cout<<mp[a]<<endl;
                    }



}



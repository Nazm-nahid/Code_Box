#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int lps[1000000];

string pattern,text;
int n,m;

int calculate_lps()
{
    int i=0,j=1;
    lps[0]=0;
    while(j<n)
    {
        if(pattern[i]==pattern[j])
        {
            lps[j]=i+1;
            i++; j++;
        }
        else
        {
            if(i!=0) i= lps[i-1];
            else {lps[j]=0; j++;}
        }
    }
   // for(int i=0;i<n;i++) cout<<lps[i]<<" "; cout<<endl;
}

int kmp()
{
    int i=0,j=0;
    while(i<m)
    {
        if(text[i]==pattern[j])
        {
            i++; j++;
        }
        else
        {
            if(j!=0) j= lps[j-1];
            else  i++;
        }
         if(j==n)
           {
               //cout<<"found"<<endl;
               cout<<i-n<<endl;
            }

    }


}

int main()
{
    //String Search Aizu - ALDS1_14_B

                        cin>>text>>pattern;
                        n=pattern.size();
                        m=text.size();
                        calculate_lps();
                       kmp();
}



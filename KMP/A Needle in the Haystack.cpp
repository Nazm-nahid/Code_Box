#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

string text,pattern;
int n,m,lps[1000010];

void calculate_lps()
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
//   return lps;
}

void kmp()
{
    int i=0,j=0,f=1;
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
               cout<<i-n<<endl;
               f=0;
            }

    }
    if(f) cout<<endl;


}

void clearr()
{
    for(int i=0;i<=n;i++)
    {
        lps[i]=0;
    }
}



int main()
{

                    while(cin>>n)
                    {
                        cin>>pattern>>text;
                        m=text.size();
                        clearr();
                        calculate_lps();
                        kmp();
                    }

}



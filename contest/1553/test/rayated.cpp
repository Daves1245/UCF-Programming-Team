#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t,c;
    string s;
    for(cin>>t;t--;)
    {
        c=0;
        cin>>s;
        if(s[s.size()-1]=='9')
        c++;
        for(long long i=0,j=s.size()-2;j>=0;i++,j--)c+=(s[j]-'0')*pow(10,i);
        cout<<c<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
    using namespace std;

int main()
{
    int t,b,p,f,h,c;
    cin>>t;
    while(t--)
{
 cin>>b>>p>>f>>h>>c;
 b/=2;
 if(h>c)
 {
     swap(h,c);
     swap(p,f);
 }
 cout<<min(f,b)*c+min(p,b-min(f,b))*h<<endl;
}
}

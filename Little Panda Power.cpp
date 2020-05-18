#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
LL powerfunction(LL a, LL b, LL x)
{
    LL ans = 1;
       while(b)
       {
           if(b&1) ans = ans * a  % x;
           b >>= 1;
           a = a * a % x;
       }
    return ans;
}
int modulusfunction(int n)
     {
       int result = n,i;
       for( i=2;i*i <= n;i++)
       {
         if (n % i == 0)
         result -= result / i;
         while (n % i == 0)
         n /= i;
       }
       if (n > 1)
       result -= result / n;
       return result;
}
int main()
 {
    int T;
    cin >> T;
    while(T--)
    {
        LL a, b, x;
        cin >> a >> b >> x;
        if(b<0) a = powerfunction(a, modulusfunction(x)-1, x),b = -b;
        cout << powerfunction(a, b, x) << endl;
    }
    return 0;
}

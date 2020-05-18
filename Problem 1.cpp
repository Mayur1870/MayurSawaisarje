#include<bits/stdc++.h>

using namespace std;

int v[20];
int a[20];
int len;
int res[20];
bool tag = false;
bool flg;

void dfs(int idx,bool flg)
{
    if(tag) return ;
    if(idx == len)
    {
        tag = true;
        return;
    }

    for(int i = 9;i >= 0;i--)
    {
        if(v[i] > 0)
        {
            if(flg || i == a[idx])
            {
                v[i]--;
                res[idx] = i;
                dfs(idx+1,flg);
                if(tag) return ;
                v[i]++;
            }
            else if(i < a[idx])
            {
                v[i]--;
                res[idx] = i;
                dfs(idx+1,true);
                if(tag) return ;
                v[i]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    string s1,s2;cin>>s1>>s2;
    if(s1.size() < s2.size())
    {
        sort(s1.rbegin(),s1.rend());
        cout<<s1<<endl;
    }
    else
    {
        len = s1.size();
        for(int i = 0;i < len;i++)
        {
            v[s1[i] - '0']++;
        }

        for(int i = 0;i < len;i++) {
            a[i] = s2[i] - '0';
        }
        dfs(0,false);
        for(int i = 0;i < len;i++)
        {
            cout<<res[i];
        }

        cout<<endl;
    }

    return 0;
}











//
//  main.cpp
//  uva 307
//
//  Created by ray on 2018/12/29.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n,len;
int sti[65],used[65];
bool dfs(int i,int l,int t)
{
    if(l==0)
    {
            t-=len;
            if(t==0) return true;
            for(i=0;used[i];++i);
                used[i]=1;
                if(dfs(i+1,len-sti[i],t)) return true;
                used[i]=0;
    }
    else
    {
        for(int j=i;j<n;++j)
        {
            if(j>0&&(sti[j]==sti[j-1]&&!used[j-1])) continue;
            
            if(!used[j]&&l>=sti[j])
            {
                l-=sti[j]; used[j]=1;
                if(dfs(j,l,t)) return true;
                used[j]=0; l+=sti[j];
                if(l==sti[j]) break;
            }
        }
    }
    return false;
}
bool cmp(const int a,const int b)
{
    return a>b;
}
int main(int argc,const char * argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n)
    {
        if(n==0) break;
        bool fl=false;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>sti[i]; sum+=sti[i];
            used[i]=0;
        }
        sort(sti,sti+n,cmp);
        for(len=sti[0];len<=sum/2;++len)
        {
            if(sum%len==0)
            {
            if(dfs(0,len,sum))
            {
                fl=true;
                cout<<len<<endl;
                break;
            }
            }
        }
        if(!fl) cout<<sum<<endl;
        
    }
    return 0;
}

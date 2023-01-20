//
//  main.cpp
//  D. Beautiful Graph
//
//  Created by ray on 2018/12/19.
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
vector<int> vec[300005];
int arr[300005];
long long mi(long long a)
{
    long long les=1,j=2;
    if(a==0)
    {
        return 1;
    }
    else
    {
        while(a>0)
        {
            if(a%2==1)
            {
                les=les*j%998244353;
            }
            a=a/2;
            j=j*j%998244353;
        }
    }
    return les;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t)
    {
        bool fl=true;
        int n,m;
        long long ans=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            arr[i]=-1;
            vec[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            long long p0=0,p1=0;
            if(arr[i]==-1)
            {
                queue<int> q;
                q.push(i);
                arr[i]=0;
                p0++;
                while(!q.empty())
                {
                    
                    int k,g;
                    k=q.front();
                    q.pop();
                    g=vec[k].size();
                    for(int j=1;j<=g;j++)
                    {
                        int c;
                        c=vec[k].back();
                        vec[k].pop_back();
                        if(arr[c]==-1)
                        {
                            if(arr[k]==0)
                            {
                                arr[c]=1;
                                p1++;
                                q.push(c);
                            }
                            else
                            {
                                arr[c]=0;
                                p0++;
                                q.push(c);
                            }
                        }
                        else
                        {
                            if(arr[c]==arr[k])
                            {
                                fl=false;
                                break;
                            }
                        }
                    }
                    
                    if(fl==false) break;
                }
                ans=ans*(mi(p0)+mi(p1))%998244353;
            }
            
            if(fl==false) break;
        }
        if(fl)
        {
            cout<<ans<<"\n";
        }
        else
        {
            cout<<"0"<<"\n";
        }
        
        t--;
    }
    
    
    return 0;
}

//
//  main.cpp
//  uva558
//
//  Created by ray on 2021/1/31.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<vector>
#include<queue>
#define MAX 100000000
using namespace std;
int d[1005]={0},cnt[1005]={0};
bool f[1005];
struct edge
{
    int to;
    int dis;
};
vector <edge> ed[1005];

bool spfa(int n,int m)
{
    queue<int> q;
    q.push(0);
    d[0]=0;
    f[0]=false;
    while(!q.empty())
    {
        int e=q.front();
        q.pop();
        f[e]=true;
        for(int i=0;i<ed[e].size();i++)
        {
            int to=ed[e][i].to,di=ed[e][i].dis;
            
                if(d[e]+di<d[to])
                {
                    d[to]=d[e]+di;
                    cnt[to]++;
                    if(cnt[to]>n)return true;
                    if(f[to])
                    {
                        f[to]=false;
                        q.push(to);
                    }
                }
        }
    }
    return false;
}
int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            ed[i].clear();
            d[i]=MAX;
            cnt[i]=0;
            f[i]=true;
        }
        
        for(int i=0;i<m;i++)
        {
            
            int f,en,dist;
            cin>>f>>en>>dist;
            ed[f].push_back({en,dist});
        }
        if(spfa(n,m))
        {
            cout<<"possible"<<endl;
        }
        else
        {
            cout<<"not possible"<<endl;
        }
    }
    return 0;
}

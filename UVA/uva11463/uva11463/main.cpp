//
//  main.cpp
//  uva11463
//
//  Created by ray on 2021/2/6.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<queue>
#include<vector>
using namespace std;
int sd[105],ed[105],use[105];
vector<int> v[105];
struct node{
    int k;
    int val;
    bool operator<(const node& n)
    const{
        return val>n.val;
    }
};
void di(int s,int d[105])
{
    priority_queue<node> pq;
    d[s]=0;
    pq.push({s,0});
    use[s]=1;
    while(!pq.empty())
    {
            node a=pq.top();
            pq.pop();
            int k=a.k,val=a.val;
            for(int i=0;i<v[k].size();i++)
            {
                if(use[v[k][i]]==0)
                {
                    use[v[k][i]]=1;
                    d[v[k][i]]=val+1;
                    pq.push({v[k][i],val+1});
                }
            }
        
    }
}
int main(int argc, const char * argv[])
{
    int a=1;
    int k=new int[a*a];
    return 0;
}

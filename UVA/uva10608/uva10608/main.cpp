//
//  main.cpp
//  uva10608
//
//  Created by 端木竣偉 on 2018/11/9.
//  Copyright © 2018年 端木竣偉. All rights reserved.
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
int res[30005],gro[30005];
int fin(int leaf)
{
    if(res[leaf]==-1)
    {
        return leaf;
    }
    
    
    return res[leaf]=fin(res[leaf]);
}
int main(int argc, const char * argv[])
{
    int a;
    cin>>a;
    while(a)
    {
        memset(res,-1,sizeof(res));
        memset(gro,-1,sizeof(gro));
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            int fir,sec;
            cin>>fir>>sec;
            int p,q;
            p=fin(fir);
            q=fin(sec);
            if(p!=q)
            {
            gro[p]=gro[p]+gro[q];
            res[q]=p;
            }
        }
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                if(sum>gro[i])
                {
                    sum=gro[i];
                }
            }
            cout<<(sum*-1)<<endl;
        
        
            a--;
    }
        
    return 0;
}

//
//  main.cpp
//  uva441
//
//  Created by ray on 2020/10/15.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int ans[20]={0},ar[20]={0};
void dfs(int now,int end,int pre)
{
    if(now==6)
    {
        for(int i=pre+1;i<=end-(6-now);i++)
        {
            ans[now]=ar[i];
            for(int j=1;j<=6;j++)
            {
                cout<<ans[j];
                if(j==6)
                {
                    cout<<endl;
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        
    }
    else
    {
        for(int i=pre+1;i<=end-(6-now);i++)
        {
            ans[now]=ar[i];
            dfs(now+1,end,i);
        }
    }
    return;
}
int main(int argc, const char * argv[])
{
    int k;
    bool f=true;
    while(cin>>k)
    {
        if(k==0)break;
        if(!f)cout<<endl;
        f=false;
        for(int i=1;i<=k;i++)
        {
            cin>>ar[i];
        }
        dfs(1,k,0);
    }
    
    return 0;
}

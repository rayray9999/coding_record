//
//  main.cpp
//  uva10926
//
//  Created by ray on 2020/10/16.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;
int rely[105][105]={0},sol[105]={0},cal[105]={0},check[105][105]={0};
void dfs(int rel,int chec)
{
        for(int i=1;i<=rely[rel][0];i++)
        {
            if(check[chec][rely[rel][i]]==0)
            {
                check[chec][rely[rel][i]]=1;
                sol[chec]++;
                dfs(rely[rel][i],chec);
            }
        }
        return;
    
}
int main(int argc, const char * argv[])
{
    int n;
    while(cin>>n)
    {
        int ans=-1,re=0;
        if(n==0)break;
        memset(rely,0,sizeof(rely));
        memset(sol,0,sizeof(sol));
        memset(cal,0,sizeof(cal));
        memset(check,0,sizeof(check));
        for(int i=1;i<=n;i++)
        {
            cin>>rely[i][0];
            for(int j=1;j<=rely[i][0];j++)
            {
                cin>>rely[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            dfs(i,i);
            if(ans==-1)
            {
                ans=sol[i];
                re=i;
            }
            else if(ans<sol[i])
            {
                ans=sol[i];
                re=i;
            }
        }
        
         cout<<re<<endl;
    }
    return 0;
}

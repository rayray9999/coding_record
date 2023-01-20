//
//  main.cpp
//  uva10908
//
//  Created by ray on 2021/1/7.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
char a[105][105];
int ma=1;
void dfs(int x,int y,int len,int m,int n,char ch)
{
    if((x-len-1)>=0&&(x+len+1)<m&&(y-len-1)>=0&&(y+len+1)<n)
    {
        bool f=true;
        for(int i=y-len-1;i<=y+len+1;i++)
        {
            if(a[x-len-1][i]!=ch||a[x+len+1][i]!=ch)
            {
                f=false;
                break;
            }
        }
        for(int i=x-len-1;i<=x+len+1;i++)
        {
            if(a[i][y-len-1]!=ch||a[i][y+len+1]!=ch)
            {
                f=false;
                break;
            }
        }
        if(f)
        {
            if(2*(len+1)+1>ma)ma=2*(len+1)+1;
            dfs(x,y,len+1,m,n,ch);
        }
    }
}
int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        ma=1;
        int m,n,q;
        cin>>m>>n>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)cin>>a[i][j];
        }
        cout<<m<<" "<<n<<" "<<q<<endl;
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            dfs(x,y,0,m,n,a[x][y]);
            
            cout<<ma<<endl;
            ma=1;
        }
    }
    
    return 0;
}

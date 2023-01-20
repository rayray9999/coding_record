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
int li[17][17],rea[17][17],re[17][17];
int n,les=-1,sum=0;
void dfs(int s,int now);
void run(int d);
int main()
{
    int a;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        memset(li,0,sizeof(0));
        memset(rea,0,sizeof(0));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>li[i][j];
                rea[i][j]=li[i][j];
                re[i][j]=li[i][j];
            }
        }
        
        dfs(n,1);
        cout<<"Case "<<i<<": "<<les<<endl;
        les=-1;
        
        
    }
    
    return 0;
}

void dfs(int s,int now)
{
    for(int i=now;i<=n;i++)
    {
        run(sum);
        if(li[1][i]==0)
        {
            li[1][i]=1;
            sum++;
            dfs(n,i);
            sum--;
            li[1][i]=0;
        }
    }
    return;
}
void run(int d)
{
    int ya=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            rea[i][j]=li[i][j];
        }
    }
    for(int i=2;i<=n+1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int ch;
            if(i==n+1)
            {
                ch=rea[i-2][j]+rea[i-1][j-1]+rea[i-1][j+1];
                if(ch%2==1)
                {
                    return ;
                }
            }
            else
            {
            ch=rea[i-2][j]+rea[i-1][j-1]+rea[i-1][j+1]+rea[i][j];
            if(ch%2==1)
            {
                if(rea[i][j]==0)
                {
                    rea[i][j]=1;
                }
                else
                {
                    return ;
                }
            }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(rea[i][j]!=re[i][j])
            {
                ya++;
            }
        }
    }
    if(les==-1)
    {
        les=ya;
    }
    else if(ya<les)
    {
        les=ya;
    }
    
    return ;
}



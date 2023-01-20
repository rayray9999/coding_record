#include <iostream>
#include<sstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <stack>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
int com[9][2],ma[9],book[9],an[9],a;
double dis[9][9];
double sum;
void dfs(int run,double how)
{
    
    if(run==a+1)
    {
        if(how<sum)
        {
            for(int i=1;i<=a;i++)
            {
                an[i]=book[i];
            }
            sum=how;
        }
        return;
    }
    for(int i=1;i<=a;i++)
    {
        if(ma[i]==0)
        {
            ma[i]=1;
            book[run]=i;
            dfs(run+1,how+dis[i][book[run-1]]);
            ma[i]=0;
        }
        
    }
    
    return;
}
int main()
{
    int ti=0;
    while(cin>>a)
    {
        if(a==0)
        {
            break;
        }
        ti++;
        sum=1000000;
        memset(book,0,sizeof(book));
        memset(dis,0,sizeof(dis));
        for(int i=1;i<=a;i++)
        {
            cin>>com[i][0];
            cin>>com[i][1];
        }
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=a;j++)
            {
                if(i!=j)
                {
                    double b,c,d;
                    b=abs(com[i][0]-com[j][0]);
                    c=abs(com[i][1]-com[j][1]);
                    d=sqrt(b*b+c*c);
                    dis[i][j]=d+16;
                    
                }
            }
        }
        dfs(1,0);
        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<ti<<endl;
        for(int i=1;i<=a-1;i++)
        {
            cout<<"Cable requirement to connect ("<<com[an[i]][0]<<","<<com[an[i]][1]<<") to ("<<com[an[i+1]][0]<<","<<com[an[i+1]][1]<<") is ";
            cout<<fixed<<setprecision(2)<<dis[an[i]][an[i+1]]<<" feet."<<endl;
        }
        cout<<"Number of feet of cable required is "<<sum<<"."<<endl;
    }
    
    
    
    return 0;
}

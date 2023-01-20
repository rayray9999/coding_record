/******************************************************************************
 
 Online C++ Compiler.
 Code, Compile, Run and Debug C++ program online.
 Write your code in this editor and press "Run" button to compile and execute it.
 
 *******************************************************************************/

#include <iostream>
#include<sstream>
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

int main()
{
    int tim,num;
    string s;
    stringstream ss;
    while(cin>>tim>>num)
    {
        int dp[21][tim+1],ma[21],rol[tim+1];
        memset(rol,0,sizeof(rol));
        memset(dp,0,sizeof(dp));
        memset(ma,0,sizeof(ma));
        int son;
        rol[0]=1;
        for(int j=1;j<=num;j++)
        {
            cin>>son;
            ma[j]=son;
            for(int i=tim;i>=0;i--)
            {
                if(rol[i]==1)
                {
                    if((son+i)<=tim)
                    {
                        rol[i+son]=1;
                        dp[j][son+i]=1;
                    }
                }
                
            }
        }
        
        int sum,big;
       
        for(int i=tim;i>=0;i--)
        {
            if(rol[i]==1)
            {
                sum=i;
                big=i;
                break;
            }
        }
        for(int i=num;i>=1;i--)
        {
            if(dp[i][big]==1)
            {
                cout<<ma[i]<<" ";
                big=big-ma[i];
            }
        }
        cout<<"sum:"<<sum<<endl;
    }
    
    return 0;
}

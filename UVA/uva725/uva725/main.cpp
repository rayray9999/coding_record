//
//  main.cpp
//  uva725
//
//  Created by ray on 2020/11/14.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int used[10]={0};
bool f=false;
void dfs(int n,int ans)
{
    if(ans>10000)
    {
        if(ans%n==0)
        {
            int k=0,l=ans,distinct[10]={0};
            bool ff=false;
            for(int i=0;i<5;i++)
            {
                distinct[l%10]=1;
                l/=10;
            }
            l=ans/n;
            for(int i=0;i<5;i++)
            {
                if(distinct[l%10]==1)ff=true;
                distinct[l%10]=1;
                    l/=10;
            }
            for(int i=0;i<=9;i++)
            {
                if(distinct[i]==0)ff=true;
            }
                if(!ff)
                {
                    cout<<ans<<" / ";
                    if(ans/n<10000)cout<<"0";
                    cout<<ans/n<<" = "<<n<<endl;
                    f=true;
                }
            
        }
    }
    else
    {
        int o=0;
        if(ans==0)o++;
        for(int i=o;i<=9;i++)
        {
            if(used[i]==0)
            {
                used[i]=1;
                dfs(n,ans*10+i);
                used[i]=0;
            }
        }
    }
}
int main(int argc, const char * argv[])
{
    bool p=false;
    int n;
    while(cin>>n)
    {
        f=false;
        for(int i=0;i<=9;i++)used[i]=0;
        if(n==0)break;
        if(!p)
        {
            p=true;
            
        }
        else
        {
            cout<<endl;
        }
        dfs(n,0);
        if(!f)cout<<"There are no solutions for "<<n<<"."<<endl;
        
    }
    
    return 0;
}

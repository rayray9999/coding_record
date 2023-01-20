//
//  main.cpp
//  uva11005
//
//  Created by ray on 2021/1/15.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
int main(int argc, const char * argv[])
{
    string s="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int t;
    cin>>t;
    for(int l=1;l<=t;l++)
    {
        int co[36]={0},ans[37]={0};
        for(int i=0;i<36;i++)cin>>co[i];
        int k;
        cin>>k;
        cout<<"Case "<<l<<":"<<endl;
        while(k--)
        {
            int g,min=-1;
            memset(ans,0,sizeof(ans));
            cin>>g;
            if(g!=0)
            {
                
                for(int i=2;i<=36;i++)
                {
                    int n=g;
                    while(n>0)
                    {
                        ans[i]+=co[n%i];
                        n/=i;
                    }
                    if(ans[i]<min||min==-1)min=ans[i];
                }
            }
            else
            {
                min=0;
            }
            cout<<"Cheapest base(s) for number "<<g<<":";
            for(int i=2;i<=36;i++)if(min==ans[i])cout<<" "<<i;
            cout<<endl;
            
        }
        if(l!=t)cout<<endl;
    }
    
    
    return 0;
}

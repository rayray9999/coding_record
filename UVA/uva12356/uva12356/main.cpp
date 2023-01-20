//
//  main.cpp
//  uva12356
//
//  Created by ray on 2021/1/17.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int s,b;
    while(cin>>s>>b)
    {
        if(s==0)break;
        int a[100005][2]={0};
        for(int i=1;i<=b;i++)
        {
            int l,r;
            cin>>l>>r;
            if(l==1)
            {
                a[1][0]=-1;
            }
            else
            {
                int g=l-1;
                while(a[g][0]!=0)
                {
                    if(a[g][0]==-1)break;
                    g=a[g][0];
                }
                a[l][0]=g;
            }
            if(r==s)
            {
                a[s][1]=-2;
            }
            else
            {
                int g=r+1;
                while(a[g][1]!=0)
                {
                    if(a[g][1]==-2)break;
                    g=a[g][1];
                }
                a[r][1]=g;
            }
            a[l][1]=a[r][1];
            a[r][0]=a[l][0];
            if(a[a[l][0]][0]!=-1&&a[l][0]!=-1)
            {
                cout<<a[l][0]<<" ";
            }
            else
            {
                cout<<"* ";
            }
            if(a[a[l][1]][1]!=-2&&a[l][1]!=-2)
            {
                cout<<a[l][1]<<endl;
            }
            else
            {
                cout<<"*"<<endl;
            }
        }
        cout<<"-"<<endl;
    }
    return 0;
}

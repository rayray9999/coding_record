//
//  main.cpp
//  uva1587
//
//  Created by ray on 2021/1/8.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<algorithm>
using namespace std;
int main(int argc, const char * argv[])
{
    int i=0;
    int p[6][2],v[6]={0};
    while(cin>>p[i][0]>>p[i][1])
    {
        if(p[i][0]<p[i][1])swap(p[i][0],p[i][1]);
        i++;
        if(i==6)
        {
            i=0;
            for(int j=0;j<6;j++)
            {
                for(int k=j+1;k<6;k++)
                {
                    if(p[j][0]==p[k][0]&&p[j][1]==p[k][1]&&v[k]==0)
                    {
                        v[k]=1;
                        v[j]=1;
                        break;
                    }
                }
            }
            bool f=true;
            for(int j=0;j<6;j++)
            {
                if(v[j]==0)
                {
                    f=false;
                }
                else
                {
                    v[j]=0;
                }
            }
            if(f)
            {
                cout<<"POSSIBLE"<<endl;
            }
            else
            {
                cout<<"IMPOSSIBLE"<<endl;
            }
        
        }
        
    }
    return 0;
}

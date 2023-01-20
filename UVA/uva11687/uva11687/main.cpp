//
//  main.cpp
//  uva11687
//
//  Created by ray on 2021/1/15.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
int d(int k)
{
    int s=1;
    while(k>0)
    {
        k/=10;
        if(k>0)s++;
    }
    return s;
}
int main(int argc, const char * argv[])
{
    string s;
    while(cin>>s)
    {
        if(s=="END")break;
        int k=0;
        if(s=="1")
        {
            cout<<1<<endl;
            continue;
        }
        k=s.length();
        int j=-1;
        for(int i=1;i>-1;i++)
        {
            if(k==j)
            {
                
                cout<<i<<endl;
                break;
            }
            else
            {
                j=k;
                k=d(k);
            }
        }
    }
    return 0;
}

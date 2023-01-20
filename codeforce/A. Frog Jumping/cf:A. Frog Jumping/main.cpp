//
//  main.cpp
//  cf:A. Frog Jumping
//
//  Created by ray on 2018/12/6.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        long long a,b,ti,u=0;
        cin>>a>>b>>ti;
        if(ti%2==0)
        {
            ti=ti/2;
        }
        else
        {
            ti=ti/2;
            u=1;
        }
        cout<<ti*(a-b)+u*a<<endl;
    }

    return 0;
}

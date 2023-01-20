//
//  main.cpp
//  cfA
//
//  Created by ray on 2020/9/15.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    long double an,t,x,y,k;
    long long ak;
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>k;
        an=(k+k*y-1)/(x-1);
        an=an+k;
        ak=an;
        if(ak!=an)
        {
            ak++;
            
        }
        cout<<ak<<endl;
    }
    return 0;
}

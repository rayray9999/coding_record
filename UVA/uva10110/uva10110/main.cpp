//
//  main.cpp
//  uva10110
//
//  Created by ray on 2021/1/25.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(int argc, const char * argv[])
{
    long long a;
    while(cin>>a)
    {
        if(a==0)break;
        int g=sqrt(a);
        if(sqrt(a)-g==0)
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}

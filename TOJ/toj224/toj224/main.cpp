//
//  main.cpp
//  toj224
//
//  Created by 端木竣偉 on 2018/11/11.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    long long a,b,sum=1;
    cin>>a>>b;
    if(a>b)
    {
        swap(a,b);
    }
    for(short int i=a;i<=b;i++)
    {
        sum=sum*i;
    }
    
    cout<<sum<<endl;
    return 0;
}

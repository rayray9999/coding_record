//
//  main.cpp
//  uva13178
//
//  Created by 端木竣偉 on 2018/12/2.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int n;
    cin>>n;
    while(n)
    {
        long long m;
        cin>>m;
        m=m%9;
        if(m==1||m==4||m==7)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
        
        n--;
    }
    return 0;
}

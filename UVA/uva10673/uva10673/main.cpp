//
//  main.cpp
//  uva10673
//
//  Created by ray on 2020/9/30.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c1,num;
        cin>>a>>b;
        if(a%b==0)
        {
            cout<<"0 "<<b<<endl;
        }
        else
        {
            c1=(a/b)+1;
            num=c1*b-a;
            cout<<num<<" "<<b-num<<endl;
        }
        
        
        
        
    }
    return 0;
}

//
//  main.cpp
//  pa:Dice Rolling
//
//  Created by ray on 2018/12/15.
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
        int x;
        cin>>x;
        if(x<=7)
        {
            cout<<"1"<<endl;
        }
        else
        {
            int k,sum;
            if(x%7==1)
            {
                cout<<(x/7)-1+2<<endl;
            }
            else if(x%7==0)
            {
                cout<<x/7<<endl;
            }
            else
            {
                cout<<(x/7)+1<<endl;
            }
        }
    }
    
    return 0;
}

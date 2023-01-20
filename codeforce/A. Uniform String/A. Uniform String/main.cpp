//
//  main.cpp
//  A. Uniform String
//
//  Created by ray on 2018/12/18.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int t;
    cin>>t;
    while(t>0)
    {
        int l,a,f;
        cin>>l>>a;
        f=l/a;
        if(l%a!=0)
        {
            for(int i=1;i<=f+l%a;i++)
            {
                cout<<"a";
            }
        }
        else
        {
            for(int i=1;i<=f;i++)
            {
                cout<<"a";
            }
        }
        for(int i=1;i<a;i++)
        {
            for(int j=1;j<=f;j++)
            {
                cout<<(char)((int)i+'a');
            }
        }
        cout<<endl;
        
        
        
        
        t--;
    }
    return 0;
}

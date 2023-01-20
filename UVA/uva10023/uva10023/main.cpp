//
//  main.cpp
//  uva10023
//
//  Created by ray on 2020/10/5.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    long long arr[25]={0};
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    for(int i=3;i<=24;i++)
    {
        for(int j=0;j<=i-1;j++)
        {
            arr[i]=arr[i]+arr[j]*arr[i-j-1];
        }
    }
    long long n;
    while(cin>>n)
    {
        for(int i=1;i<=25;i++)
        {
            if(arr[i]==n)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}

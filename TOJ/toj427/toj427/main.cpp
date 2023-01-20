//
//  main.cpp
//  toj427
//
//  Created by ray on 2019/1/24.
//  Copyright © 2019年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
long long arr[1000005],sum[1000005];

int main(int argc, const char * argv[])
{
    for(int i=1;i<=1000000;i++)
    {
        arr[i]+=(i+1)*2-1;
        for(int j=i*2;j<=1000000;j+=i) arr[j]-=arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    
    int a;
    while(cin>>a) cout<<sum[a]<<endl;
    return 0;
}

//
//  main.cpp
//  uva10107
//
//  Created by 端木竣偉 on 2018/11/8.
//  Copyright © 2018年 端木竣偉. All rights reserved.
//

#include <iostream>
#include<algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int a,tim=0,arr[10005],poi;
    
    while(cin>>a)
    {
        tim++;
        arr[tim]=a;
        poi=tim/2;
        sort(arr+1,arr+tim+1);
        if(tim%2==0)
        {
             cout<<(arr[poi]+arr[poi+1])/2<<endl;
        }
        else
        {
            cout<<arr[poi+1]<<endl;
        }
    }
    return 0;
}

//
//  main.cpp
//  B. Teams Forming
//
//  Created by ray on 2018/12/18.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[])
{
    int a[105]={0},p;
    cin>>p;
    for(int i=1;i<=p;i++)
    {
        int k;
        cin>>k;
        a[i]=k;
    }
    sort(a+1,a+p+1);
    int sum=0;
    for(int i=1;i<=p;i+=2)
    {
        sum=sum+a[i+1]-a[i];
    }
    cout<<sum<<endl;
    return 0;
}

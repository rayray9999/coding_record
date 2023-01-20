//
//  main.cpp
//  uva350
//
//  Created by ray on 2021/1/25.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int z,i,m,l,g=0;
    while(cin>>z>>i>>m>>l)
    {
        if(z==0&&i==0&&m==0&&l==0)break;
        int a[10005]={0},len=1;
        a[l]=1;
        while(a[(z*l+i)%m]==0)
        {
            len++;
            l=(z*l+i)%m;
            a[l]=len;
        }
        g++;
        cout<<"Case "<<g<<": "<<len+1-a[(z*l+i)%m]<<endl;
    }
    return 0;
}

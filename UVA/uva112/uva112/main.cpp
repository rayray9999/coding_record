//
//  main.cpp
//  uva112
//
//  Created by ray on 2018/12/23.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
#include<sstream>
using namespace std;
int arr[100000];

void re(int ro)
{
    int a;
    int k;
    cin>>k>>a;
    if(a!=')')
    {
        arr[ro*2]=a;
        re(ro*2);
    }
    cin>>k>>a;
    if(a!=')')
    {
        
        arr[ro*2+1]=a;
        re(ro*2+1);
    }
    return;
    
}
int main(int argc, const char * argv[])
{
    int an;
    while(cin>>an)
    {
        
        memset(arr,-1,sizeof(arr));
        int r;
        int k;
        cin>>k>>r;
        arr[1]=r;
        re(1);
        for(int i=1;i<=15;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    
    
    return 0;
}

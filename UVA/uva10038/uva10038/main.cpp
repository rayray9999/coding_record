//
//  main.cpp
//  uva10038
//
//  Created by ray on 2020/10/4.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main(int argc, const char * argv[])
{
    int n,k;
    while(cin>>n)
    {
        bool f=true;
        int arr[3000]={0};
        cin>>k;
        for(int i=2;i<=n;i++)
        {
            int g;
            cin>>g;
            arr[abs(g-k)]=1;
            k=g;
        }
        for(int i=1;i<n;i++)
        {
            if(arr[i]==0)f=false;
            
        }
        if(f)
        {
            cout<<"Jolly"<<endl;
        }
        else
        {
            cout<<"Not jolly"<<endl;
        }
    }
    return 0;
}

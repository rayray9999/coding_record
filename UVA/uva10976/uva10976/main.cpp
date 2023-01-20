//
//  main.cpp
//  uva10976
//
//  Created by ray on 2020/11/20.
//  Copyright © 2020年 ray. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[])
{
    int k,ans[20000][2];
    while(cin>>k)
    {
        int sum=0;
        for(int y=k+1;y<=2*k;y++)
        {
            if(k*y%(y-k)==0)
            {
                sum++;
                ans[sum][0]=(k*y)/(y-k);
                ans[sum][1]=y;
            }
        }
        cout<<sum<<endl;
        for(int i=1;i<=sum;i++)
        {
            cout<<"1/"<<k<<" = 1/"<<ans[i][0]<<" + 1/"<<ans[i][1]<<endl;
        }
    }
    return 0;
}

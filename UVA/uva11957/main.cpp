//
//  main.cpp
//  uva11957
//
//  Created by 端木竣偉 on 2018/9/28.
//  Copyright © 2018年 端木竣偉. All rights reserved.
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

int main()
{
    int a;
    cin>>a;
    for(int ca=1;ca<=a;ca++)
    {
        int bang,sx,sy;
        cin>>bang;
        long long arr[bang+1][bang+1];
        memset(arr,0,sizeof(arr));
        for(int i=1;i<=bang;i++)
        {
            for(int j=1;j<=bang;j++)
            {
                char po;
                cin>>po;
                if(po=='.')
                {
                    arr[i][j]=0;
                }
                else if(po=='B')
                {
                    arr[i][j]=-1;
                }
                else
                {
                    sx=i;
                    sy=j;
                    arr[i][j]=1;
                }
            }
        }
        
        for(int i=sx;i>=2;i--)
        {
            for(int j=1;j<=bang;j++)
            {
                if(arr[i][j]>=1)
                {
                    if(arr[i-1][j+1]==-1)
                    {
                        if(arr[i-2][j+2]!=-1)
                        {
                            arr[i-2][j+2]=(arr[i-2][j+2]+arr[i][j])%1000007;
                        }
                    }
                    else
                    {
                        arr[i-1][j+1]=(arr[i-1][j+1]+arr[i][j])%1000007;
                    }
                    
                    if(arr[i-1][j-1]==-1)
                    {
                        if(arr[i-2][j-2]!=-1)
                        {
                            arr[i-2][j-2]=(arr[i-2][j-2]+arr[i][j])%1000007;
                        }
                    }
                    else
                    {
                        arr[i-1][j-1]=(arr[i-1][j-1]+arr[i][j])%1000007;
                    }
                    
                }
            }
        }
        long long sum=0;
        for(int i=1;i<=bang;i++)
        {
            if(arr[1][i]!=-1)
            {
                sum=(sum+arr[1][i])%1000007;
            }
        }
        cout<<"Case "<<ca<<": "<<sum<<endl;
        
    }
    
    return 0;
}

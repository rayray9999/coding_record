//
//  main.cpp
//  uva10106
//
//  Created by ray on 2018/12/13.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int arr[505];
int main(int argc, const char * argv[])
{
    
    string a,b;
    while(getline(cin,a))
    {
        getline(cin,b);
        memset(arr,0,sizeof(arr));
        int la,lb;
        la=a.length();
        lb=b.length();
        for(int i=la-1;i>=0;i--)
        {
            int n=a[i]-'0';
            for(int j=lb-1;j>=0;j--)
            {
                int m=b[j]-'0',w=la+lb-i-j-2;
                m=m*n;
                while(m>0)
                {
                    int k;
                    k=m%10;
                    arr[w]=arr[w]+k;
                    m=m/10;
                    if(arr[w]>=10)
                    {
                        m+=arr[w]/10;
                        arr[w]=arr[w]%10;
                    }
                    w++;
                }
                
            }
        }
        int y=0;
        for(int i=0;i<=505;i++)
        {
            arr[i]=arr[i]+y;
            if(arr[i]>=10)
            {
                y=arr[i]/10;
                arr[i]=arr[i]%10;
            }
        }
        int nu=0;
        for(int i=505;i>=0;i--)
        {
            if(arr[i]!=0)
            {
                nu=i;
                break;
            }
        }
        for(int i=nu;i>=0;i--)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}

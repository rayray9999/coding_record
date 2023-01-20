//
//  main.cpp
//  uva534
//
//  Created by ray on 2021/1/25.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<math.h>
using namespace std;
int main(int argc, const char * argv[])
{
    int n,p=1;
    while(cin>>n)
    {
        if(n==0)break;
        int a[205][2]={0};
        int shr[205]={0};
        int v[205]={0};
        int sx,sy;
        cin>>sx>>sy;
        for(int i=1;i<n;i++)cin>>a[i][0]>>a[i][1];
        for(int i=1;i<n;i++)
        {
            shr[i]=(a[i][0]-sx)*(a[i][0]-sx)+(a[i][1]-sy)*(a[i][1]-sy);
        }
        for(int i=1;i<n;i++)
        {
            int m=-1;
            int x=-1;
            for(int j=1;j<n;j++)
            {
                if(v[j]==0)
                {
                    if(x==-1||m>shr[j])
                    {
                        m=shr[j];
                        x=j;
                    }
                }
            }
            v[x]=1;
            if(x==1)break;
            for(int j=1;j<n;j++)
            {
                if(j!=x)
                {
                    int g=(a[j][0]-a[x][0])*(a[j][0]-a[x][0])+(a[j][1]-a[x][1])*(a[j][1]-a[x][1]);
                    if(g<shr[j]&&shr[x]<shr[j])
                    {
                        shr[j]=max(g,shr[x]);
                    }
                }
            }
        }
        cout<<"Scenario #"<<p<<endl;
        cout<<"Frog Distance = ";
        printf("%.3f",sqrt(shr[1]));
        cout<<endl<<endl;
        p++;
    }
    
    return 0;
}

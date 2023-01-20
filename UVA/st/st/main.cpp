//
//  main.cpp
//  st
//
//  Created by ray on 2021/4/22.
//

#include <iostream>
#include<string>
using namespace std;

int main(int argc, const char * argv[])
{
    
    int a[1000]={0},b[1000]={0};
    for(int i=1;i<=22;i++)
    {
        memset(b,0,sizeof(b));
        b[2]=1;
        b[7]=1;
        b[13]=1;
        b[32]=1;
        int c[4]={2,7,13,32};
        for(int j=1;j<i;j++)
        {
            for(int k=500;k>=0;k--)
            {
                if(b[k]!=0)
                {
                    for(int l=0;l<4;l++)
                    {
                        if(c[l]+k<500)
                        {
                            b[k+c[l]]+=b[k];
                            
                        }
                    }
                    b[k]=0;
                }
            }
        }
        for(int k=0;k<500;k++)
        {
            a[k]+=b[k];
        }
    }
    cout<<a[49]<<endl;
    return 0;
}

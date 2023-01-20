//
//  main.cpp
//  uva478(math)
//
//  Created by ray on 2019/1/30.
//  Copyright © 2019年 ray. All rights reserved.
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
#include <math.h>
#include<sstream>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[])
{
    char ch,si[15];
    int ti=1;
    long double arr[15][4][2];
    while(cin>>ch)
    {
        if(ch=='*') break;
        si[ti]=ch;
        if(ch=='r')
        {
            double lx,ly,rx,ry;
            cin>>lx>>ly>>rx>>ry;
            arr[ti][0][0]=lx;
            arr[ti][0][1]=ly;
            arr[ti][1][0]=rx;
            arr[ti][1][1]=ry;
        }
        else if(ch=='c')
        {
            cin>>arr[ti][1][0]>>arr[ti][1][1]>>arr[ti][0][0];
        }
        else
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<2;j++)
                {
                    cin>>arr[ti][i][j];
                }
                 
            }
        }
        ti++;
    }
    double x,y;
    int t=0;
    while(cin>>x>>y)
    {
        if(x==9999.9&&y==9999.9) break;
        bool fla=false;
        t++;
        for(int i=1;i<ti;i++)
        {
            bool fl=false;
                if(si[i]=='r')
                {
                    if(x>arr[i][0][0]&&x<arr[i][1][0])
                    {
                        if(y<arr[i][0][1]&&y>arr[i][1][1])
                        {
                            fl=true;
                        }
                    }
                }
                else if(si[i]=='c')
                {
                    long double a,b,c;
                    a=abs(arr[i][1][0]-x);
                    b=abs(arr[i][1][1]-y);
                    c=arr[i][0][0];
                    if(c*c>(a*a+b*b))
                    {
                        fl=true;
                    }
                }
                else
                {
                    bool d=true;
                    long double x1,y1,x2,y2,abc,sum=0;
                    abc=arr[i][0][0]*arr[i][1][1]+arr[i][1][0]*arr[i][2][1]+arr[i][2][0]*arr[i][0][1];
                    abc=abc-(arr[i][0][1]*arr[i][1][0])-(arr[i][1][1]*arr[i][2][0])-(arr[i][2][1]*arr[i][0][0]);
                    abc=abs(abc*0.5);
                    for(int j=0;j<3;j++)
                    {
                        x1=arr[i][j][0];
                        y1=arr[i][j][1];
                        x2=arr[i][(j+1)%3][0];
                        y2=arr[i][(j+1)%3][1];
                        sum=sum+abs(0.5*(x1*y2+x2*y+x*y1-y1*x2-y2*x-y*x1));
                        
                        if((x1*y2+x2*y+x*y1-y1*x2-y2*x-y*x1)==0) d=false;
                    }
                    
                        if(abs(abc-sum)<=0.0000001&&d)
                        {
                            fl=true;
                        }
                    }
            
                    if(fl)
                    {
                        fla=true;
                        cout<<"Point "<<t<<" is contained in figure "<<i<<endl;
                    }
            
        }
        
        if(!fla) cout<<"Point "<<t<<" is not contained in any figure"<<endl;
    }
    
    return 0;
}

//
//  main.cpp
//  toj432
//
//  Created by ray on 2018/12/12.
//  Copyright © 2018年 ray. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int die[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int n,m,anx,any,ban[1005][1005],book[1005][1005];
bool ki=true;
int main(int argc, const char * argv[])
{
    int ax,ay,k;
    queue<int> qx;
    queue<int> qy;
    cin>>n>>m>>ax>>ay>>anx>>any;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        int fx,fy;
        cin>>fx>>fy;
        ban[fx][fy]=-1;
    }
    qx.push(ax);
    qy.push(ay);
    book[ax][ay]=1;
    while(1)
    {
        int x,y;
        x=qx.front();
        y=qy.front();
        qx.pop();
        qy.pop();
        for(int i=0;i<=3;i++)
        {
            int fx,fy;
            fx=x+die[i][0];
            fy=y+die[i][1];
            if(fx<=n&&fx>0&&fy<=m&&fy>0)
            {
                if(book[fx][fy]!=1&&ban[fx][fy]!=-1)
                {
                        book[fx][fy]=1;
                        qx.push(fx);
                        qy.push(fy);
                }
            }
        }
        if(book[anx][any]==1)
        {
            ki=false;
            break;
        }
        if(qy.empty())
        {
            break;
        }
    }
    if(ki==true)
    {
        cout<<"Harakiri!"<<endl;
    }
    else
    {
        cout<<"Cool!"<<endl;
    }
    return 0;
}

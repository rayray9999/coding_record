//
//  main.cpp
//  uva11213
//
//  Created by ray on 2021/1/7.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
struct no
{
    string s;
    int num;
    no* next;
};
int main(int argc, const char * argv[])
{
    no* a[100005];
    int ans[100005];
    string as[100005];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        a[i]=new no;
        no* nod=a[i];
        for(int j=k;j>=1;j--)
        {
            string st;
            cin>>st;
            nod->s=st;
            if(j==1)as[i]=st;
            nod->num=j;
            nod->next=new no;
            nod=nod->next;
            
        }
        ans[i]=k;
        for(int j=i-1;j>=0;j--)
        {
            
            if(as[j]==as[i])
            {
                
                no* l1=a[i],*l2=a[j];
                int gg=min(l1->num,l2->num);
                
                if((k-gg)<ans[i])
                {
                    while(l1->num>gg)l1=l1->next;
                    while(l2->num>gg)l2=l2->next;
                    int anss=gg;
                    for(int m=gg;m>1;m--)
                    {
                        if(l1->s!=l2->s)
                        {
                            
                            anss=m-1;
                        }
                        l1=l1->next;
                        l2=l2->next;
                    }
                    if((k-anss)<ans[i])ans[i]=k-anss;
                }
            }
        }
    }
    cin.ignore();
    int sum=0;
    for(int i=0;i<n;i++)sum+=ans[i];
    cout<<sum<<endl;
    return 0;
}

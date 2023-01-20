//
//  main.cpp
//  uva245
//
//  Created by ray on 2021/1/7.
//  Copyright © 2021年 ray. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
struct no
{
    char a[50];
    int len;
    no* next;
    
};
int main(int argc, const char * argv[])
{
    string s;
    no* h=new no;
    while(getline(cin,s))
    {
        
        if(s[0]=='0')break;
        
        int len=0;
        char ar[50];
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<='z'&&s[i]>='a')
            {
                ar[len]=s[i];
                len++;
            }
            else if(s[i]<='Z'&&s[i]>='A')
            {
                ar[len]=s[i];
                len++;
            }
            else if(s[i]<='9'&&s[i]>='0')
            {
                int num=0;
                for(;i<s.length();i++)
                {
                    if(s[i]>'9'||s[i]<'0')break;
                    num*=10;
                    num=num+s[i]-'0';
                }
                if(i!=s.length()||s[i]<='9'||s[i]>='0')i--;
                if(num==1)
                {
                    for(int j=0;j<h->len;j++)
                    {
                        cout<<h->a[j];
                    }
                }
                else
                {
                    no* fi=h,*go;
                    for(int i=2;i<num;i++)
                    {
                        fi=fi->next;
                        
                    }
                    go=fi->next;
                    for(int j=0;j<go->len;j++)
                    {
                        cout<<go->a[j];
                    }
                    fi->next=go->next;
                    go->next=h;
                    h=go;
                }
                
            }
            else
            {
                if(len!=0)
                {
                    no* nd=new no;
                    for(int j=0;j<len;j++)
                    {
                        nd->a[j]=ar[j];
                        cout<<ar[j];
                    }
                    nd->next=h;
                    nd->len=len;
                    h=nd;
                    len=0;
                }
                
                cout<<s[i];
            }
        }
        if(len!=0)
        {
            no* nd=new no;
            for(int j=0;j<len;j++)
            {
                nd->a[j]=ar[j];
                cout<<ar[j];
            }
            nd->next=h;
            h=nd;
            nd->len=len;
            len=0;
        }
        cout<<endl;
    }
    return 0;
}

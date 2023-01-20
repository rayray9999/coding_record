#include <iostream>
#include<sstream>
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
int ani[500005],en[500005];
int fi(int leaf)
{
    if(ani[leaf]==-1)
    {
        return leaf;
    }
    return ani[leaf]=fi(ani[leaf]);
}
int main(int argc, const char * argv[])
{
    int man;
    string s;
    cin>>man;
    memset(ani,-1,sizeof(ani));
    memset(en,-1,sizeof(en));
    cin.ignore();
    while(getline(cin,s))
    {
        stringstream ss(s);
        string fin,usless,typ;
        int p,q;
        int fir,sec;
        ss>>fin;
        ss>>usless;
        ss>>typ;
        ss>>fir;
        ss>>sec;
        if(fin[0]=='y')
        {
           
                p=fi(fir);
                q=fi(sec);
                if(en[p]!=-1)
                {
                    en[p]=fi(en[p]);
                }
                if(en[q]!=-1)
                {
                    en[q]=fi(en[q]);
                }
                if(typ[0]=='f')
                {
                    if(en[p]==q||en[q]==p)
                    {
                        cout<<"angry"<<endl;
                    }
                    else if(p!=q)
                    {
                        
                        if(en[p]!=-1&&en[q]!=-1&&en[p]!=en[q])
                        {
                            ani[en[p]]=en[q];
                        }
                        if(en[p]!=-1)
                        {
                            en[q]=en[p];
                        }
                        else if(en[q]!=-1)
                        {
                            en[p]=en[q];
                        }
                        ani[p]=q;
                    }
                }
                else
                {
                    if(p==q)
                    {
                        cout<<"angry"<<endl;
                    }
                    else if(en[p]!=q)
                    {
                        if(en[p]!=-1)
                        {
                            ani[en[p]]=q;
                        }
                        if(en[q]!=-1)
                        {
                            ani[en[q]]=p;
                        }
                        en[p]=q;
                        en[q]=p;
                    }
                }
        }
        else
        {
            p=fi(fir);
            q=fi(sec);
            
            if(typ[0]=='f')
            {
                if(p==q)
                {
                    cout<<"yeap"<<endl;
                }
                else
                {
                    cout<<"nope"<<endl;
                }
            }
            else
            {
                if(en[p]!=-1)
                {
                    en[p]=fi(en[p]);
                }
                if(en[q]!=-1)
                {
                    en[q]=fi(en[q]);
                }
                if(en[p]==q)
                {
                    cout<<"yeap"<<endl;
                
                }
                else
                {
                    cout<<"nope"<<endl;
                }
            }
        }
    }
    




    return 0;
}

//
//  main.cpp
//  ㄠ
//
//  Created by ray on 2021/4/29.
//

#include <iostream>
using namespace std;
void k(int *a)
{
    a=2+a;
    cout<<*a;
}
int main(int argc, const char * argv[])
{
    int a= 1;
    k(&a);
    cout<<a;
    return 0;
}

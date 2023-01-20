#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <fstream>
#include<vector>
#include<string>
using namespace std;

class Vector
{
private:
    vector<double> ve;

public:
    //constructor
    Vector() {ve.clear();};

    //overload
    Vector operator +(Vector v)
    {
        for(int i=0;i<ve.size();i++)
        {
            v.ve[i]+=ve[i];
        }
        return v;
    }
    Vector operator -(Vector v)
    {
        for(int i=0;i<ve.size();i++)
        {
            v.ve[i]=ve[i]-v.ve[i];
        }
        return v;
    }
    Vector  operator ^(Vector v)
    {
        for(int i=0;i<ve.size();i++)
        {
            v.ve[i]*=ve[i];
        }
        return v;
    }// dot product
    Vector operator *(double a)
    {
        Vector v;
        for(int i=0;i<ve.size();i++)
        {
            v.ve.push_back(ve[i]*a);
        }
        return v;
    }// cross product

    //input output overload
    friend istream& operator >> (istream& in, Vector& v)
    {
        int k;
        in>>k;
        v.ve.clear();
        for(int i=0;i<k;i++)
        {
            double l;
            in>>l;
            v.ve.push_back(l);
        }
        return in;
    }
    friend ostream& operator << (ostream& out, const Vector& v)
    {
        out<<'(';
        for(int i=0;i<v.ve.size();i++)
        {
            out<<v.ve[i];
            if(i!=v.ve.size()-1)
            {
                out<<',';
            }
            else
            {
                out<<')';
            }
        }
        return out;
    }
    
};

#endif

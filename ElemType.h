#include<iostream>
#include<vector>
using namespace std;
class ElemType{

public:
    int key;
    int value;
ElemType():key(0),value(0){}
ElemType(int a,int b):key(a),value(b)
{}
ElemType(const ElemType& e):key(e.key),value(e.value){}
~ElemType(){}

bool operator<(const ElemType & a)
{
    return key<a.key;
}

ElemType& operator = (const ElemType &a){
    key = a.key;
    value = a.value;
    return *this;

}
// friend ostream & operator<<(ostream &out,const ElemType & a);
};

ostream & operator<<(ostream &out,const ElemType & a){
    out<<"("<<a.key<<","<<a.value<<")";
    return out;
}

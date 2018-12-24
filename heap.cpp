/*
 * @Author: lemn 
 * @Date: 2018-12-24 08:20:35 
 * @Last Modified by: lemn
 * @Last Modified time: 2018-12-24 08:24:32
 */
// #include<iostream>
#include<vector>
#include"ElemType.h"
#include"heap.h"
using namespace std;

// const int intMax = 1<<31;

// class ElemType{

// public:
//     int key;
//     int value;
// ElemType():key(0),value(0){}
// ElemType(int a,int b):key(a),value(b)
// {}
// ElemType(const ElemType& e):key(e.key),value(e.value){}
// ~ElemType(){}

// bool operator<(const ElemType & a)
// {
//     return key<a.key;
// }

// ElemType& operator = (const ElemType &a){
//     key = a.key;
//     value = a.value;
//     return *this;

// }
// friend ostream & operator<<(ostream &out,const ElemType & a);
// };

// ostream & operator<<(ostream &out,const ElemType & a){
//     out<<"("<<a.key<<","<<a.value<<")";
//     return out;
// }


// const int BUFF_SIZE=100;
// class Heap{
// public:
//     // ElemType maxElem(intMax,0);
//     int Length=0;
//     vector<ElemType> mydata = vector<ElemType>(BUFF_SIZE);

// Heap(vector<ElemType> array){
//     Length = array.size();
//     for(int i=0;i<Length;i++)
//         mydata[i]=array[i];
//     // mydata.push_back(ElemType(intMax,0));
// }
// void build();

// void insertElem(ElemType e);

// ElemType deleteMin();

// void deleteElem(int index);

// void changeElem(int index,int chg);

// private:

// void percolateDown(int index);

// void percolateUp(int index);

// };

void Heap::percolateDown(int index){
    ElemType tmp = mydata[index];
    int child,i;
    for(i=index;i<int(Length/2);)
    {
        child = i*2+1;
        if(child+1<Length&&mydata[child+1]<mydata[child])
            child++;
        if(mydata[child]<tmp)
            mydata[i] = mydata[child];
        else{
            break;
        }
        i = child;
    }
    mydata[i] = tmp;
    return;
}

void Heap::percolateUp(int index){
    ElemType tmp = mydata[index];
    int parent,i;
    for(i=index;i>0;)
    {
        parent = int((i-1)/2);
        if(tmp<mydata[parent])
            mydata[i]=mydata[parent];
        else
            break;
        i=parent;
    }
    mydata[i]=tmp;
    return;
}

void Heap::build()
{
    cout<<"build heap"<<endl;
    for(int i = int(Length/2)-1;i>=0;i--)
        percolateDown(i);   
    return;
}

void Heap::insertElem(ElemType e){
    cout<<"insert elem "<<e<<endl;
    mydata[Length++] = e;
    percolateUp(Length-1);
    return;
}

ElemType Heap::deleteMin(){
    cout<<"delete min elem"<<endl;
    ElemType ret = mydata[0];
    mydata[0] = mydata[--Length];
    percolateDown(0);
    return ret;
}

void Heap::changeElem(int index,int chg){
    cout<<"change "<<index<<"\'s with "<<chg<<endl;
    if(chg==0) return;
    mydata[index].key +=chg;
    if(chg<0){
        percolateUp(index);
    }
    else{
        percolateDown(index);
    }
    return;
}

// void printHeap(Heap heap){
//     for(int i=0;i<heap.Length;++i)
//     {
//         cout<<(i==0?"(":" (")<<heap.mydata[i].key<<','<<heap.mydata[i].value<<")";
//     }
//     cout<<endl;
//     return;
// }
// int main()
// {
//     vector<ElemType> array(10);
//     for(int i=0;i<10;i++)
//     {
//         array[i].key=10-i;
//         array[i].value=0;
//     }
//     Heap heap(array);
//     heap.build();
//     printHeap(heap);
//     ElemType tmp = heap.deleteMin();
//     cout<<tmp.key<<endl;
//     printHeap(heap);
//     heap.insertElem(ElemType(2,1));
//     printHeap(heap);
//     heap.changeElem(5,2);
//     printHeap(heap);
//     heap.changeElem(6,-10);
//     printHeap(heap);
//     return 0;
// }
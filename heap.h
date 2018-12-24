/*
 * @Author: lemn 
 * @Date: 2018-12-24 08:22:10 
 * @Last Modified by: lemn
 * @Last Modified time: 2018-12-24 08:23:55
 */

#include<vector>
#include"ElemType.h"
using namespace std;
const int BUFF_SIZE=100;
class Heap{
public:
    // ElemType maxElem(intMax,0);
    int Length=0;
    vector<ElemType> mydata = vector<ElemType>(BUFF_SIZE);

Heap(vector<ElemType> array){
    Length = array.size();
    for(int i=0;i<Length;i++)
        mydata[i]=array[i];
    // mydata.push_back(ElemType(intMax,0));
}
void build();

void insertElem(ElemType e);

ElemType deleteMin();

void deleteElem(int index);

void changeElem(int index,int chg);

private:

void percolateDown(int index);

void percolateUp(int index);

};

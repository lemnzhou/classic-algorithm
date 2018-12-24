/*
 * @Author: lemn 
 * @Date: 2018-12-24 04:14:36 
 * @Last Modified by: lemn
 * @Last Modified time: 2018-12-24 08:20:11
 */

#include<iostream>
#include<vector>
#include<algorithm>    //swap is used.
#include"ElemType.h"
#include"sorted.h"
using namespace std;

/***********insertSort*************/
void insertSort(vector<ElemType> & array,int left,int right)
{
    for(int i=left+1;i<=right;i++)
    {
        ElemType tmp = array[i];
        int j;
        for(j=i-1;j>=left;j--)
        {
            if(tmp<array[j])
            {
                array[j+1]=array[j];
            }
            else
            {
                break;
            }
        }
        array[j+1]=tmp;
    }
}


/**********quickSort**************/
ElemType median3(vector<ElemType>& array,int left,int right)
{
    /*
    use the median of the left elem,the center elem,the right elem as the pivot elem;
    and let the left elem is the min of the three,the right is the max of the three,
    the center elem is the median.and replace the center elem and the right-1 ,to be 
    the last elem of the unpartion array[left->right-1].
    */
    int center = (left+right)/2;
    if(array[center]<array[left]){
        swap(array[left],array[center]);
    }
    if(array[right]<array[left]){
        swap(array[left],array[right]);
    }
    if(array[right]<array[center]){
        swap(array[right],array[center]);
    }
    swap(array[center],array[right-1]);
    return array[right-1];
}

void quickSort(vector<ElemType>& array,int left,int right)
{
    int i,j;
    ElemType pivot;
    const int cutoff=3;
    if(left+cutoff<=right)
    {
        pivot = median3(array,left,right);
        i=left,j=right-1;
        for(;;)
        {
            while(array[++i]<pivot){}
            while(pivot<array[--j]){}
            if(i<j)
            {
                swap(array[i],array[j]);
            }
            else
                break;
        }
        swap(array[i],array[right-1]);
        quickSort(array,left,i-1);
        quickSort(array,i+1,right);
    }
    else
        insertSort(array,left,right);
}


/***********heapSort***************/
/*build a max heap and then pop max elem to the last of array to get sorted array*/

void percolateDown(vector<ElemType>&array,int n,int index)
//n is the len of the heap
{
    ElemType tmp = array[index];
    int i,child;
    for(i=index;i<n/2;)  //index child or grandchild but non-leaf node.
    {
        child = i*2+1;
        if(child+1<n && array[child]<array[child+1])
        {
            child++;
        }
        if(tmp<array[child])
        {
            array[i]=array[child];
        }
        else
            break;
        i=child;
    }
    array[i]=tmp;
}

void heapSort(vector<ElemType>&array)
{
    //build maxheap
    int n = array.size();
    for(int i=n/2-1;i>=0;--i)
    {
        percolateDown(array,n,i);
    }
    //sorted
    for(int i= n-1;i>0;--i)
    {
        swap(array[0],array[i]);
        percolateDown(array,i,0);
    }
}

/*********mergeSort*************/
void mergeSort(vector<ElemType>&array,int left,int right)
{
    if(left>=right) {
        return;
    }  
    int median = (left+right)/2;
    mergeSort(array,left,median);
    mergeSort(array,median+1,right);
    //merge two sorted array.
    vector<ElemType> tmp=vector<ElemType>(right-left+1);
    int i=left,j=median+1,k=0;
    while(i<=median&&j<=right){
        if(array[j]<array[i]){        //keep stable
            tmp[k++]=array[j++];
        }
        else{
            tmp[k++]=array[i++];
        }
    }
    while(i<=median){tmp[k++]=array[i++];}
    while(j<=right){tmp[k++]=array[j++];}
    k=0;
    while(k<tmp.size()){array[k+left]=tmp[k];k++;}
}


// void printArray(vector<ElemType> array)
// {
//     for(int i=0;i<array.size();++i)
//     {
//         cout<<(i==0?"":" ")<<array[i];
//     }
//     cout<<endl;
// }
// int main()
// {
//     const int N =20;
//     vector<ElemType> array=vector<ElemType>(N);
//     for(int i=0;i<N;++i)
//     {
//         array[i]=ElemType(N-i,0);
//     }
//     printArray(array);
//     vector<ElemType> tmp = array;
//     insertSort(tmp,0,tmp.size()-1);
//     printArray(tmp);
//     tmp = array;
//     quickSort(tmp,0,tmp.size()-1);
//     printArray(tmp);
//     tmp = array;
//     heapSort(tmp);
//     printArray(tmp);
//     tmp = array;
//     mergeSort(tmp,0,tmp.size()-1);
//     printArray(tmp);
//     return 0;
// }
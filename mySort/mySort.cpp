#include"mySort.h"
#include<iostream>
#include<vector>

void mySort::display(){
    std::cout<<"Your vector is:\n";
    for(int &i: myVec){
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}

void mySort::my_Merge(int l,int m,int r){
    int i,j,k;
    int n1,n2;
    n1 = m - l +1;
    n2 = r- m ;
    int L[n1],R[n2];
    for(i = 0;i<n1;i++){
        L[i] = myVec[l+i];
    }
    for(j = 0;j<n2;j++){
        R[j] = myVec[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            myVec[k] = L[i];
            i++;
        }
        else{
            myVec[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        myVec[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        myVec[k] = R[j];
        j++;
        k++;
    }
}

void mySort::my_Merge_Sort(int l,int r){
    if(l < r){
        int m = l + (r-l)/2;
        my_Merge_Sort(l,m);
        my_Merge_Sort(m+1,r);
        my_Merge(l,m,r);
    }
}

void mySort::my_Quick_sort(int l,int r){
    int pivot = myVec[(l+r)/2];
    int i = l;
    int j = r;
    while (i < j)
    {
        while (myVec[i] < pivot){
            i++;
        }
        while (myVec[j] > pivot){
            j--;
        }
        if(i <= j){
            int temp;
            temp = myVec[i];
            myVec[i] = myVec[j];
            myVec[j] = temp;
            i++;
            j--;
        }
    }
    
    if(i<r){
        this->my_Quick_sort(i,r);
    }
    if(j>l){
        this->my_Quick_sort(l,j);
    }
}

void mySort::my_Bubble_sort(){
    std::cout<<"After using Bubble Sort\n";
    for(int i=1;i<myVec.size();i++){
        for(int j=myVec.size()-1;j>=i;j--){
            if(myVec[j]<myVec[j-1]){
                std::swap(myVec[j],myVec[j-1]);
            }
        }
    }
    for(auto &i:myVec){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

void mySort::my_selection_sort(){
    std::cout<<"After using Selection Sort:\n";
    for(int i=0;i<myVec.size()-1;i++){
        int index_min = i;
        for(int j=i+1;j<myVec.size();j++){
            if(myVec[index_min] > myVec[j]){
                index_min = j;
            }
        }
        if(index_min != i){
            int temp = myVec[index_min];
            myVec[index_min] = myVec[i];
            myVec[i] = temp;
        }
    }
    for(auto &i: myVec){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
#include"mySearch.h"
#include<iostream>
#include<algorithm>

void mySearch::display(){
    std::cout<<"Your vector is:";
    for(auto &i:myVec){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

bool mySearch::Sequential(const int& number){
    for(const int &i: myVec){
        if(i == number){
            return true;
        }
    }
    return false;
}

bool mySearch::Binary(const int& number){
    std::sort(myVec.begin(),myVec.end());
    int left = 0;
    int right = myVec.size()-1;
    while (left<=right){
        int mid = left + (right - left)/2;
        if(myVec[mid] == number){
            return true;
        }
        else if(myVec[mid] > number){
            right = mid -1;
        }
        else{
            left = mid + 1;
        }
    }
    return false;
}
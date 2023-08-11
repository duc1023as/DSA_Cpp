#include<iostream>
#include<vector>
#include<string>
#include"mySearch/mySearch.h"

int main(){
    std::vector<int> vec;
    int size;
    int number;
    std::cout<<"PLease enter your vector size:\n";
    std::cin>>size;
    std::cout<<"Please enter your vector element\n";
    for(int i=0;i<size;i++){
        int temp;
        std::cin>>temp;
        vec.push_back(temp);
    }
    mySearch mySearch1(vec);
    mySearch1.display();
    std::cout<<"Please enter your number that you want to find it:\n";
    std::cin>>number;
    std::cout<<"Result:"<<mySearch1.Sequential(number)<<"\n";
    std::cout<<"Result:"<<mySearch1.Binary(number)<<"\n";
    return 0;
}
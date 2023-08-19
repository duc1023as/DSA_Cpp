#include<iostream>
#include<vector>
#include<string>
// #include"mySearch/mySearch.h"
#include"mySort/mySort.h"

int main(){
    std::vector<int> vec;
    int size;
    std::cout<<"PLease enter your vector size:\n";
    std::cin>>size;
    std::cout<<"Please enter your vector element\n";
    for(int i=0;i<size;i++){
        int temp;
        std::cin>>temp;
        vec.push_back(temp);
    }
    mySort mySort1(vec);
    mySort1.display();
    mySort1.my_Merge_Sort(0,size-1);
    // mySort1.my_Quick_sort(0,size-1);
    mySort1.display();
    // mySort1.my_Bubble_sort();
    return 0;
}
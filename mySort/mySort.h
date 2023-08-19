#ifndef mySort_H
#define mySort_H

#include<vector>

class mySort{
    private:
        std::vector<int> myVec;
    public:
        mySort(const std::vector<int> &vec) : myVec(vec) {}
        void display();
        void my_selection_sort();
        void my_Bubble_sort();
        void my_Quick_sort(int,int);
        void my_Merge(int,int,int);
        void my_Merge_Sort(int,int);
};

#endif
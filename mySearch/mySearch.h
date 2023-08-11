#ifndef mySearch_H
#define mySearch_H

#include<vector>

class mySearch{
    private:
        std::vector<int> myVec;
    public:
        mySearch(std::vector<int> &vec) : myVec(vec) {}
        bool Sequential(const int& number);
        bool Binary(const int& number);
        void display();
};

#endif
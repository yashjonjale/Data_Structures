// #include<iostream>
// using namespace std;
#ifndef UNION_FIND_H
#define UNION_FIND_H
#include<bits/stdc++.h>



template<typename T>
class union_find{
    private:
    std::map<T,std::pair<T,int> dict;
    size_t size;
    public:
    union_find();
    union_find(std::vector<T> lst);

    void insert(T& key);

    T* find_set(T& key);

    bool equivalent(T& k1,T& k2);

    T& union_(T& k1, T& k2);

    bool key_exists(T& key);
};
#endif

// template<>
// class union_find<int>{
//     private:
//     std::vector<int> dict;
//     size_t size;
//     public:
//     union_find();
//     union_find(int N);

//     void insert(int key);

//     int* find_set(int key);

//     bool equivalent(int k1,int k2);

//     int& union_sets(int k1, int k2);
// };
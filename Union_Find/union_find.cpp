#include"union_find.h"
#include<bits/stdc++.h>

template<typename T>
union_find<T>::union_find(){
    //no keys
    size = 0;
}


template<typename T>
union_find<T>::union_find(std::vector<T> lst){
    //no keys
    size = lst.size();
    for(auto itr : lst){
        dict[*itr].first=*itr;
        dict[*itr].second=1;
    }
}

template<typename T>
void union_find<T>::insert(T& key){
    if(!key_exists(T)){
        size++;
        dict[key].first=key;
        dict[key].second = 1;
    }
}

template<typename T>
bool union_find<T>::key_exists(T& key){
    return dict.find(key) != dict.end();
}

template<typename T>
T* union_find<T>::find_set(T& key){
    //with path compression -> sometimes you cannot use due to problem constraints
    if(dict[key].first==key){
        return &(dict[key].first);
    }
    T* key2 = find_set((dict[key].first));
    dict[key].first=*key2;
    return key2;
}

template<typename T>
bool union_find<T>::equivalent(T& k1,T& k2){
    return find_set(k1)==find_set(k2);
}

template<typename T>
T& union_find<T>::union_(T& k1, T& k2){
    T* k_1 = find_set(k1);
    T* k_2 = find_set(k2);
    int size1 = dict[*k1].second;
    int size2 = dict[*k2].second;
    if(size1>size2){
        dict[*k1].second = size1+size2;
        dict[*k2].first = *k1;
        size--;
        return *k1;
    }
    else{
        dict[*k2].second = size1+size2;
        dict[*k1].first = *k2;
        size--
        return *k2;
    }

}


template<>
class union_find<int>{
    private:
    std::vector<std::pair<int,int>> dict;
    size_t size;
    public:
    union_find(){
        size = 0;
    }
    union_find(int N){
        dict.resize(N);
        for(int i =0;i<N;i++){
            dict[i].first=i;
            dict[i].second = 1;
        }
        size = N;
    }

    void insert(int key){
        dict.push_back({size,1});
        size++;
    }

    int find_set(int key){
        if(dict[key].first==key){
            return key;
        }
        int nk = find_set(dict[key].first);
        dict[key].first=nk;
        return nk;
    }

    bool equivalent(int k1,int k2){
        return find_set(k1)==find_set(k2);
    }

    int union_sets(int k1, int k2){
        int a1 = find_set(k1);
        int a2 = find_set(k2);
        if(dict[a1].second>dict[a2].second){
            dict[a1].second +=dict[a2].second;
            dict[a2].first = a1;
            size--;
            return a1;
        }
        else{
            dict[a2].second +=dict[a1].second;
            dict[a1].first = a2;
            size--;
            return a2;
        }
    }
};
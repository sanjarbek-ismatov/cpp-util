#include <utility>
#include <iostream>
#include "sort.hpp"

using namespace std;
Sort::Sort(string type): type(std::move(type)){}

vector<int> Sort::sort(vector<int> arr) {
    _arr = std::move(arr);
    if(type == "bubble") return bubbleSort();
    else if(type == "selection") return selectionSort();
    else if(type == "insertion") return insertionSort();
    else if(type == "quick") return quickSort();
    else if(type == "merge") return mergeSort();
    return _arr;
};

vector<int> Sort::bubbleSort() {
    bool swapped;
    do{
        swapped = false;
        for(int i = 0; i < _arr.size() - 1; i++){
            if(_arr[i] > _arr[i + 1]){
                int curr = _arr[i];
                _arr[i] = _arr[i + 1];
                _arr[i + 1] = curr;
                swapped = true;
            }
        }
    }while(swapped);
    return _arr;
}
vector<int> Sort::selectionSort() {

}
vector<int> Sort::insertionSort() {
    for(int i = 1; i < _arr.size(); i++){
        int curr = _arr[i];
        int j = i - 1;
        while(j > -1 && _arr[j] > curr){
                _arr[j + 1] = _arr[j];
                j--;
        }
        _arr[j + 1] = curr;
    }
    return _arr;
}
vector<int> Sort::quickSort() {

}
vector<int> Sort::mergeSort() {

}

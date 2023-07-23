#include <utility>
#include <iostream>
#include <cmath>
#include "sort.hpp"

using namespace std;
Sort::Sort(string type): type(std::move(type)) {}

vector < int > Sort::sort(vector < int > arr) {
    _arr = std::move(arr);
    if (type == "bubble") return bubbleSort();
    else if (type == "selection") return selectionSort();
    else if (type == "insertion") return insertionSort();
    else if (type == "quick") return quickSort();
    else if (type == "merge") return mergeSort();
    return _arr;
};

vector < int > Sort::bubbleSort() {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < _arr.size() - 1; i++) {
            if (_arr[i] > _arr[i + 1]) {
                int curr = _arr[i];
                _arr[i] = _arr[i + 1];
                _arr[i + 1] = curr;
                swapped = true;
            }
        }
    } while (swapped);
    return _arr;
}
vector < int > Sort::selectionSort() {
    for (int i = 0; i < _arr.size(); i++) {
        int min = i;
        for (int j = i + 1; j < _arr.size(); j++) {
            if (_arr[min] > _arr[j]) min = j;
        }
        if (min != i) {
            int curr = _arr[i];
            _arr[i] = _arr[min];
            _arr[min] = curr;
        }
    }
    return _arr;
}
vector < int > Sort::insertionSort() {
    for (int i = 1; i < _arr.size(); i++) {
        int curr = _arr[i];
        int j = i - 1;
        while (j > -1 && _arr[j] > curr) {
            _arr[j + 1] = _arr[j];
            j--;
        }
        _arr[j + 1] = curr;
    }
    return _arr;
}
vector < int > Sort::quickSort() {
    return quickSortFunction(_arr);
}
vector < int > Sort::quickSortFunction(vector < int > arr) {
    if (arr.size() <= 1) return arr;
    int pivotIndex = floor(arr.size() / 2);
    vector < int > left;
    vector < int > right;

    for (int i = 0; i < arr.size(); i++) {
        if (i == pivotIndex) continue;
        if (arr[i] < arr[pivotIndex]) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }
    vector < int > leftSorted = quickSortFunction(left);
    vector < int > rightSorted = quickSortFunction(right);
    vector < int > merged;
    merged.insert(merged.end(), leftSorted.begin(), leftSorted.end());
    merged.push_back(arr[pivotIndex]);
    merged.insert(merged.end(), rightSorted.begin(), rightSorted.end());
    return merged;
}
vector < int > Sort::mergeSort() {
    return mergeSortFunction(_arr);
}
vector < int > Sort::mergeSortFunction(vector < int > arr) {
    if (arr.size() <= 1) return arr;
    int mid = floor(arr.size() / 2);
    vector < int > left(arr.begin(), arr.begin() + mid);
    vector < int > right(arr.begin() + mid, arr.end());
    vector < int > leftSort = mergeSortFunction(left);
    vector < int > rightSort = mergeSortFunction(right);
    return merge(leftSort, rightSort);
}
vector < int > Sort::merge(vector < int > left, vector < int > right) {
    vector < int > merge;
    int leftIndex = 0;
    int rightIndex = 0;
    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex] >= right[rightIndex]) {
            merge.push_back(right[rightIndex]);
            rightIndex++;
        } else {
            merge.push_back(left[leftIndex]);
            leftIndex++;
        }
    }
    while (leftIndex < left.size()) {
        merge.push_back(left[leftIndex]);
        leftIndex++;
    }
    while (rightIndex < right.size()) {
        merge.push_back(right[rightIndex]);
        rightIndex++;
    }
    return merge;
}
#include <utility>
#include <iostream>
#include <cmath>
#include "sort.hpp"

using namespace std;
Sort::Sort(string type): type(std::move(type)) {}

vector < int > Sort::sort(vector < int > arr) {
    _arr = std::move(arr);
    if (type == "bubble") return bubble_sort();
    else if (type == "selection") return selection_sort();
    else if (type == "insertion") return insertion_sort();
    else if (type == "quick") return quickSort();
    else if (type == "merge") return merge_sort();
    return _arr;
};

vector < int > Sort::bubble_sort() {
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
vector < int > Sort::selection_sort() {
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
vector < int > Sort::insertion_sort() {
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
    return quick_sort_function(_arr);
}
vector < int > Sort::quick_sort_function(vector < int > arr) {
    if (arr.size() <= 1) return arr;
    int pivot_index = floor(arr.size() / 2);
    vector < int > left;
    vector < int > right;

    for (int i = 0; i < arr.size(); i++) {
        if (i == pivot_index) continue;
        if (arr[i] < arr[pivot_index]) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }
    vector < int > left_sorted = quick_sort_function(left);
    vector < int > right_sorted = quick_sort_function(right);
    vector < int > merged;
    merged.insert(merged.end(), left_sorted.begin(), left_sorted.end());
    merged.push_back(arr[pivot_index]);
    merged.insert(merged.end(), right_sorted.begin(), right_sorted.end());
    return merged;
}
vector < int > Sort::merge_sort() {
    return merge_sort_function(_arr);
}
vector < int > Sort::merge_sort_function(vector < int > arr) {
    if (arr.size() <= 1) return arr;
    int mid = floor(arr.size() / 2);
    vector < int > left(arr.begin(), arr.begin() + mid);
    vector < int > right(arr.begin() + mid, arr.end());
    vector < int > left_sort = merge_sort_function(left);
    vector < int > right_sort = merge_sort_function(right);
    return merge(left_sort, right_sort);
}
vector < int > Sort::merge(vector < int > left, vector < int > right) {
    vector < int > merge;
    int left_index = 0;
    int right_index = 0;
    while (left_index < left.size() && right_index < right.size()) {
        if (left[left_index] >= right[right_index]) {
            merge.push_back(right[right_index]);
            right_index++;
        } else {
            merge.push_back(left[left_index]);
            left_index++;
        }
    }
    while (left_index < left.size()) {
        merge.push_back(left[left_index]);
        left_index++;
    }
    while (right_index < right.size()) {
        merge.push_back(right[right_index]);
        right_index++;
    }
    return merge;
}
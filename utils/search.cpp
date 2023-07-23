#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include "sort.hpp"
#include "search.hpp"

using namespace std;
Search::Search(string sort_type, string search_type): sort_type(std::move(sort_type)), search_type(std::move(search_type)) {};
int Search::search(vector < int > arr, int target) {
    Sort sort_util(this -> sort_type);
    this -> sorted_arr = sort_util.sort(std::move(arr));
    if (this -> search_type == "linear")
        return this->linear_search(this->sorted_arr, target);
    else if (this -> search_type == "binary")
        return this->binary_search(this->sorted_arr, target);
    return -1;
};

int Search::linear_search(vector < int > arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
};
int Search::binary_search(vector < int > arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int mid = 0;
    while (left <= right) {
        mid = floor((left + right) / 2);
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}
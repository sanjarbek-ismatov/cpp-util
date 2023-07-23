// search.hpp
#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <string>
#include <vector>

class Search {
public:
    Search(std::string sort_type, std::string search_type);
    int search(std::vector<int> arr, int target);
    std::vector<int> sorted_arr;
private:
    std::string sort_type;
    std::string search_type;
    int linear_search(vector<int> arr, int target);
    int binary_search(vector<int> arr, int target);
};

#endif // SEARCH_HPP


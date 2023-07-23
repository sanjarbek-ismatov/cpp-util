#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Sort{
public:
    Sort(string type);
    string type;
    vector<int> sort(vector<int> arr);
private:
    vector<int> _arr;
    vector<int> bubble_sort();
    vector<int> selection_sort();
    vector<int> insertion_sort();
    vector<int> quickSort();
    vector<int> merge_sort();
    vector<int> quick_sort_function(vector<int> arr);
    vector<int> merge_sort_function(vector<int> arr);
    vector<int> merge(vector<int> left, vector<int> right);
};

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
    vector<int> bubbleSort();
    vector<int> selectionSort();
    vector<int> insertionSort();
    vector<int> quickSort();
    vector<int> mergeSort();
    vector<int> quickSortFunction(vector<int> arr);
    vector<int> mergeSortFunction(vector<int> arr);
    vector<int> merge(vector<int> left, vector<int> right);
};

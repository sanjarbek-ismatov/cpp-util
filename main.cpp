#include <vector>
#include <iostream>
#include <string>
#include "utils/search.hpp"
using namespace std;
int main(){
    vector<int> arr = {4, 4, 6, 2, 6, 7, 3, 1, 7, 8};
    Search searchUtils("quick", "binary");
    int target;
    string def = "[ ";
    for (int elem : arr) {
        def += to_string(elem);
        def += " ";
    }
    def += "]";
    cout << "Current array: " << def << endl;
    cout << "Target: ";
    cin >> target;
    int result = searchUtils.search(arr, target);
    string sorted = "[ ";
    for (int elem : searchUtils.sorted_arr) {
        sorted += to_string(elem);
        sorted += " ";
    }
    sorted += "]";

    cout << "Sorted array: " << sorted << endl;

    cout << "Searing element: " << target << endl;
    cout << "It's result (index): " << result << endl;
    return 0;
}
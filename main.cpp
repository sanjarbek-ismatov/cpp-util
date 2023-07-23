#include <vector>
#include <string>
#include "utils/sort.hpp"
int main(){
    Sort sortUtils = Sort("merge");
    vector<int> unsortedArr = {5, 4, 3, 1, 2};
    vector<int> sortedArr = sortUtils.sort(unsortedArr);
    string value;
    for(int i : sortedArr){
        value += to_string(i);
        value += " ";
    }
    cout << value << endl;
    return 0;
}
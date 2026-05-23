#include <vector>

using namespace std;

template <typename ItemType>
void insertionSort(vector<ItemType>& vector) {
    for (int j = 1; j < vector.size(); j++) {
        if (j == vector.size() - 2) {
            int a = 1;
        }
        int key = vector[j];
        int i = j;
        while (i > 0 && vector[i - 1] > key) {
            vector[i] = vector[i - 1];
            i -= 1; 
        }
        vector[i] = key;
    }
}
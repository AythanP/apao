#include <vector>

using namespace std;

template <typename ItemType>
void bubbleSort(vector<ItemType>& vector) {
   for (int i = 0; i < vector.size(); i++) {
    for (int j = vector.size() - 1; j > i; j--) {
        if (vector[j] < vector[j - 1]) {
            swap(vector[j], vector[j - 1]);
        }
    }
   }
};
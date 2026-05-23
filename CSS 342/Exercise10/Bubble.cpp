#include <vector>

using namespace std;

template <typename ItemType>
void bubbleSort(vector<ItemType>& vector) {
   for (int i = 0; i < vector.size(); i++) {
    for (int j = vector.size() - 1; j > i; j--) {
        if (vector.at(j) < vector.at(j - 1)) {
            swap(vector.at(j), vector.at(j - 1));
        }
    }
   }
};
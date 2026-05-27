#include <vector>
#include <stdexcept>

using namespace std;

template <typename ItemType>
int linearSearch(const vector<ItemType> vector, ItemType target) {
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == target) {
            return i;
        }
    }

    return -1;
}
#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename T1, typename T2>
void printMap(const map<T1, T2>& myMap);

int main() {
    map<string, int> myMap1;
    myMap1.emplace("Apple", 100);
    myMap1.emplace("Orange", 200);
    myMap1.emplace("Banana", 300);
    myMap1.emplace("Guava", 400);
    myMap1.emplace("Strawberry", 500);
    printMap(myMap1);

    pair<map<string, int>::iterator, bool> attempt1 = myMap1.insert(pair<string, int>("Apple", 200));
    if (attempt1.second == true) {
        cout << "Sucessfully inserted integer 200 to key string Apple: " << attempt1.second << endl;
    } else {
        cout << "Unsucessfully inserted integer 200 to key string Apple: " << attempt1.second << endl;
    }
    
    pair<map<string, int>::iterator, bool> attempt2 = myMap1.insert(pair<string, int>("Starfruit", 200));
    if (attempt2.second == true) {
        cout << "Sucessfully inserted integer 200 to key string Starfruit: " << attempt2.second << endl;
    } else {
        cout << "Unsucessfully inserted integer 200 to key string Starfruit: " << attempt2.second << endl;
    }

    // There are no runtime errors 
    printMap(myMap1);
    myMap1.insert(pair<string, int>("Mango", 900));
    printMap(myMap1);
    myMap1["Avacado"] = 400;
    printMap(myMap1);
    
    // There are no runtime errors
    printMap(myMap1);
    myMap1["Orange"] = 750;
    printMap(myMap1);
    // insert() doesn't change the value at the key
    myMap1.insert(pair<string, int>("Orange", 500));
    printMap(myMap1);
}

template <typename T1, typename T2>
void printMap(const map<T1, T2>& myMap) {
    for (typename map<T1, T2>::const_iterator it = myMap.begin(); it != myMap.end(); it++) {
        cout << it->first << " " << it->second << " ";
    }
    cout << endl;
}
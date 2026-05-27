#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include "BinarySearch.cpp"
#include "LinearSearch.cpp"

static random_device rd;
static default_random_engine generator(rd());
static uniform_int_distribution<int> distribution(1, 1024);

void binarySearchGame();
void binarySearchGameAuto();
int cpu1(int guess, int target);
int cpu2(int low, int high);
int randomNumber () { return distribution(generator); }
void populateVector(vector<int>& vector, int length);

int main() {
    /*
    vector<int> vector = {3, 7, 12, 18, 22, 27, 35};
    int target = binarySearch(vector, 18);
    cout << target << endl;

    int targetRecursive = binarySearchRecursive(vector, 7, 0, vector.size() - 1);
    cout << targetRecursive << endl;
    */

    //binarySearchGame();
    //binarySearchGameAuto();

    vector<int> vector1;
    populateVector(vector1, pow(2, 10));
    vector<int> vector2;
    populateVector(vector2, pow(2, 13));
    vector<int> vector3;
    populateVector(vector3, pow(2, 16));
    vector<int> vector4;
    populateVector(vector4, pow(2, 19));
    vector<int> vector5;
    populateVector(vector5, pow(2, 22));

    chrono::high_resolution_clock::time_point start1 = chrono::high_resolution_clock::now();
    int target1 = linearSearch(vector1, 500);
    chrono::high_resolution_clock::time_point stop1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
    cout << "Linear search for a vector of size " << vector1.size() << " took " << duration1.count() << " microseconds" << endl;
    bool found1 = target1 = 500 ? true : false;
    cout << found1 << endl;

    sort(vector1.begin(), vector1.end());
    chrono::high_resolution_clock::time_point start12 = chrono::high_resolution_clock::now();
    int target12 = binarySearch(vector1, 500);
    chrono::high_resolution_clock::time_point stop12 = chrono::high_resolution_clock::now();
    auto duration12 = chrono::duration_cast<chrono::microseconds>(stop12 - start12);
    cout << "Binary search for a vector of size " << vector1.size() << " took " << duration12.count() << " microseconds" << endl;
    bool found12 = target12 = 500 ? true : false;
    cout << found12 << endl;

    /*
    chrono::high_resolution_clock::time_point start13 = chrono::high_resolution_clock::now();
    int target13 = binarySearch(vector1, 500);
    chrono::high_resolution_clock::time_point stop13 = chrono::high_resolution_clock::now();
    auto duration13 = chrono::duration_cast<chrono::microseconds>(stop13 - start13);
    cout << "Recursive binary search for a vector of size " << vector1.size() << " took " << duration13.count() << " microseconds" << endl;
    bool found13 = target13 = 500 ? true : false;
    cout << found13 << endl;
    */
}

// function to play a guessing game using the binary search algorithm 
void binarySearchGame() {
    int computerTarget = distribution(generator);
    int playerTarget;
    do {
        cout << "Pick a number between 1 and 1024" << endl;
        cin >> playerTarget;
        if (playerTarget > computerTarget) {
            cout << "Your number was larger than the computer's number" << endl;
        } else if (playerTarget < computerTarget) {
            cout << "Your number was smaller than the computer's number" << endl;
        } else {
            cout << "You have found the number!" << endl;
        }
    } while (playerTarget != computerTarget);
    cout << "Computer's number: " << computerTarget << endl;
}

void binarySearchGameAuto() {
    int target = distribution(generator);
    int low = 1;
    int high = 1024;
    int middle = cpu2(low, high);
    int success = cpu1(middle, target);
    do {
        if (success == -1) {
            middle = cpu2(middle + 1, high);
            success = cpu1(middle, target);
        } else if (success == 1) {
            middle = cpu2(low, middle - 1);
            success = cpu1(middle, target);
        }
    } while (success != 0);
    cout << "Cpu1 numeber found: " << target << endl;
}

int cpu1(int guess, int target) {
    if (guess < target) {
        return -1;
    } else if (guess > target) {
        return 1;
    } else {
        return 0;
    }
}

int cpu2(int low, int high) {
    int middle = (low + high) / 2;
    cout << "Cpu2 guessed " << middle << endl;
    return middle;
}

// Function to populate an integer vector with random numbers, given its desired length
// Requires a random number generator function as a dependency
// Should also work with vector floats and doubles
void populateVector(vector<int>& vector, int length) {
    vector = std::vector<int>(length);
    generate(vector.begin(), vector.end(), randomNumber);
}
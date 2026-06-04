#include <cmath>
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <stdexcept>
#include "Sorting.h"

template <typename ItemType>
void printVector(const vector<ItemType> &vector);
template <typename ItemType>
void writeVector(vector<ItemType>& data, int indicator, int algorithm, ofstream& fout);
template <typename ItemType>
double calculateSortingAlgorithmAverageRuntime(vector<ItemType>& data, void (*sortingFunction)(vector<ItemType> &data, int beginning, int end));

enum Algorithms {
    BUBBLE, INSERTION, MERGE, QUICK
};

static const int TOTAL_NUMBER_OF_VECTORS = 15;

static random_device rd;
static default_random_engine generator(rd());

int main(int argc, char *argv[]) {
    ofstream fout("assignment5.csv");
    fout << "vector size,initial sorting order,sorting algorithm,average runtime (seconds)" << endl;
    vector<vector<int>> data = vector<vector<int>>(TOTAL_NUMBER_OF_VECTORS);
    int power = 10, base = 2;
    for (int i = 0; i < TOTAL_NUMBER_OF_VECTORS; i++) {
        if (i % 3 == 0 && i != 0 && i < 9) {
            power += 3;
        // Reduced power due to machine limitations
        } else if (i == 9 || i == 12) {
            power += 1;
        }
        data[i] = vector<int>(pow(base, power));
        
        // populate a vector in ascending order
        if (i % 3 == 0) {
            for (int j = 0; j < data[i].size(); j++) {
                data[i][j] = j;
            }
        // populate a vector in descending order
        } else if (i % 3 == 1) {
            int max = data[i].size();
            for (int j = 0; j < data[i].size(); j++) {
                data[i][j] = max;
                max--;
            }
        // populate a vector randomly
        }  else if (i % 3 == 2) {
            uniform_int_distribution<int> distribution(1, data[i].size());
            for (int j = 0; j < data[i].size(); j++) {
                data[i][j] = distribution(generator);
            }
        }

        writeVector(data[i], i % 3, BUBBLE, fout);
        writeVector(data[i], i % 3, INSERTION, fout);
        writeVector(data[i], i % 3, MERGE, fout);
        writeVector(data[i], i % 3, QUICK, fout);
    }

    fout.close();
}

// function to print a vector to console for debugging purposes
template <typename ItemType>
void printVector(const vector<ItemType>& data) {
    for (int i = 0; i < 50; i++)
    {
        if (i >= 25 && i % 25 == 0)
        {
            cout << endl;
        }
        cout << data.at(i) << " ";
    }
    cout << endl << endl;
}

// Function to sort a vector and write relevant data to a provided .csv file
// Data: vector size, initial order, sorting algorithm, time taken to sort
template <typename ItemType>
void writeVector(vector<ItemType>& data, int indicator, int algorithm, ofstream& fout) {
    if (fout.is_open()) {
        string initialSortingOrder;
        switch(indicator) {
            case 0:
                initialSortingOrder = "ascending";
                break;
            case 1:
                initialSortingOrder = "descending";
                break;
            case 2:
                initialSortingOrder = "random";
                break;
            default:
                throw invalid_argument("Error: writeVector() cannot determine initial sorting order");
        }

        string sortingAlgorithm;
        double averageRuntime = 0.0;
        switch(algorithm) {
            case BUBBLE:
                sortingAlgorithm = "bubble";
                averageRuntime = calculateSortingAlgorithmAverageRuntime(data, Sorting<int>::bubbleSort);
                break;
            case INSERTION:
                sortingAlgorithm = "insertion";
                averageRuntime = calculateSortingAlgorithmAverageRuntime(data, Sorting<int>::insertionSort);
                break;
            case MERGE:
                sortingAlgorithm = "merge";
                averageRuntime = calculateSortingAlgorithmAverageRuntime(data, Sorting<int>::mergeSort);
                break;
            case QUICK:
                sortingAlgorithm = "quick";
                averageRuntime = calculateSortingAlgorithmAverageRuntime(data, Sorting<int>::quickSort);
                break;
            default:
                throw invalid_argument("Error: writeVector() cannot determine the sorting algorithm used");
        }

        fout << data.size() << "," << initialSortingOrder << "," << sortingAlgorithm << "," << averageRuntime << endl;
    }
}

// Function to calculate the average runtime of a sorting algorithm from the Sorting class in seconds
// Average: sorting algorithm is run 5 times before division
template <typename ItemType>
double calculateSortingAlgorithmAverageRuntime(vector<ItemType>& data, void (*sortingFunction)(vector<ItemType> &data, int beginning, int end)) {
    vector<ItemType> copy(data);

    double average = 0.0;
    for (int j = 0; j < 5; j++) {
        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
        sortingFunction(copy, 0, data.size() - 1);
        chrono::high_resolution_clock::time_point stop = chrono::high_resolution_clock::now();
        chrono::duration<double> timeSpan = chrono::duration_cast<chrono::duration<double>>(stop - start);
        average += timeSpan.count();
        copy = data;
    }
    average /= 5.0;
    
    return average;
}
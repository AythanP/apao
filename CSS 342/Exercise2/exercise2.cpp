#include <cstdlib>
#include <iostream>

using namespace std;

class Flower {
    private:
    string name;
    int numberOfPetals;
    float price;

    public: 
    // argument constructor
    Flower(string name, int numberOfPetals, float price) {
        this->name = name;
        this->numberOfPetals = numberOfPetals;
        this->price = price;
    }

    // default constructor
    Flower() {
        name = "Rose";
        numberOfPetals = 5;
        price = 5.00;
    }    

    // copy constructor
    Flower(const Flower& other) {
        name = other.name;
        numberOfPetals = other.numberOfPetals;
        price = other.price;
    }

    // setter functions
    void setName(string name) {
        this->name = name;
    }
    void setNumberOfPetals(int numberOfPetals) {
        this->numberOfPetals = numberOfPetals;
    }
    void setPrice(float price) {
        this->price = price;
    }

    // getter functions
    string getName() {
        return this->name;
    }
    int getNumberOfPetals() {
        return this->numberOfPetals;
    }
    float getPrice() {
        return this->price;
    }

    // other functions
    void printInfo() {
        cout << "Flower name: " << this->name << "\nNumber of petals: " << this->numberOfPetals << "\nPrice of flower: " << this->price << endl;
    }
};

int main() {
    Flower rose;
    rose.printInfo();
}
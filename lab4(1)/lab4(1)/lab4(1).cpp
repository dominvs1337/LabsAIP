#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime> 
using namespace std;

int main() {

    const int SIZE = 256;
    int numbers[SIZE];

    // Seed the random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    // Fill the array with random numbers from 1 to 1000
    for (int i = 0; i < SIZE; ++i) {
        numbers[i] = rand() % 1000 + 1;
    }

    // Print the numbers in different formats
    for (int i = 0; i < SIZE; ++i) {
        cout << dec << setw(6) << numbers[i] << "  ";
        cout << hex << setw(4) << numbers[i] << "  ";
        cout << oct << setw(4) << numbers[i] << "  ";
        cout << dec << setw(6) << numbers[i] << "  ";

        if ((i + 1) % 4 == 0) {
            std::cout << std::endl; // Start a new line after every 4 numbers
        }
    }

    return 0;
}
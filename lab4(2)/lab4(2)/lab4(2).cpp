#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>

using namespace std;

void prepareInputFile(const string& inputFile) {
    ofstream outFile(inputFile);

    if (!outFile) {
        cerr << "Ошибка при открытии файла для записи: " << inputFile << endl;
        return;
    }

    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 100; ++i) {
        int randomNum = rand() % 101 - 50;
        outFile << randomNum << endl;
    }

    outFile.close();
    cout << "Файл " << inputFile << " успешно создан." << endl;
}

void processFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile) {
        cerr << "Ошибка при открытии входного файла: " << inputFile << endl;
        return;
    }
    if (!outFile) {
        cerr << "Ошибка при открытии выходного файла: " << outputFile << endl;
        return;
    }

    vector<int> numbers;
    int num;


    while (inFile >> num) {
        numbers.push_back(num);
    }


    int minimum = numeric_limits<int>::max();
    for (int n : numbers) {
        if (n < minimum) {
            minimum = n;
        }
    }


    int squareOfMin = minimum * minimum;


    for (int n : numbers) {
        if (n > 0) {
            outFile << squareOfMin << endl;
        }
        else {
            outFile << n << endl;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Файл " << outputFile << " успешно создан." << endl;
}

int main() {
    setlocale(0, "");
    const string inputFile = "input.txt";
    const string outputFile = "output.txt";

    prepareInputFile(inputFile);
    processFile(inputFile, outputFile);

    return 0;
}

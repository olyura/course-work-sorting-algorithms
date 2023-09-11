// Бібліотека допоміжних функцій для роботи з даними
#ifndef DATA_H
#define DATA_H

#include <iostream>

#include <vector>
#include <sstream>

#include <fstream>

#include <cstdlib> // rand

#include <limits> // numeric_limits

using namespace std;

// Створення файлу з відсортованими даними
void outputFile(int array[], int size) {
  ofstream outfile ("sortedData.txt");
  string data;
  for (int i = 0; i < size; i++) {
    data += to_string(array[i]) + " ";
  }
  outfile << data;
  outfile.close();
  cout << "Sorted data is stored in the file 'sortedData.txt'." << endl;
}

// Формування вектора з введених даних
vector<int> arrayFromInputInt(string rawArray) {  
  vector<int> arr; 

  stringstream ss(rawArray);
  string digit;
  while (ss >> digit) {
    arr.push_back(stoi(digit));
  }
  return arr;
}

// Ручний ввід масиву
string handArray() {
  string rawArray = ""; 
  cout << "Enter integers divided by spaces\n";
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  getline(cin, rawArray);
  return rawArray;
}

// Довільний масив
string randomArray(int size = 100, int limit = 10) {
  string rawArray = "";
  for (int i = 0; i < size; i++) {
    rawArray += to_string(rand() % limit) + " ";
  }
  return rawArray;
}

// Отримані даних масива з файлу
string arrayFromFile (string pathToFile) {
  string rawArray;
  ifstream testFile;
  testFile.open(pathToFile);
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  cout << "Array From File " << pathToFile << endl;
  return rawArray;
}

#endif
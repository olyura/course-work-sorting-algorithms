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

// Отримання тестових масивів з файлів

// Масив з файлу counting1000asc.txt
string counting1000asc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/counting1000asc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу counting1000desc.txt
string counting1000desc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/counting1000desc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу counting10000asc.txt
string counting10000asc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/counting10000asc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу counting10000desc.txt
string counting10000desc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/counting10000desc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу counting100000asc.txt
string counting100000asc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/counting100000asc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу counting100000desc.txt
string counting100000desc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/counting100000desc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// ------------------------------

// Масив з файлу radix1000asc.txt
string radix1000asc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/radix1000asc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу radix1000desc.txt
string radix1000desc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/radix1000desc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу radix10000asc.txt
string radix10000asc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/radix10000asc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу radix10000desc.txt
string radix10000desc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/radix10000desc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу radix100000asc.txt
string radix100000asc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/radix100000asc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу radix100000desc.txt
string radix100000desc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/radix100000desc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// ------------------------------

// Масив з файлу bucket1000asc.txt
string bucket1000asc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/bucket1000asc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу bucket1000desc.txt
string bucket1000desc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/bucket1000desc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу bucket10000asc.txt
string bucket10000asc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/bucket10000asc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу bucket10000desc.txt
string bucket10000desc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/bucket10000desc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу bucket100000asc.txt
string bucket100000asc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/bucket100000asc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

// Масив з файлу bucket100000desc.txt
string bucket100000desc() {
  string rawArray;
  ifstream testFile;
  testFile.open("testArrays/bucket100000desc.txt");
  if ( testFile.is_open() ) {
    getline(testFile, rawArray);
  }
  return rawArray;
}

#endif
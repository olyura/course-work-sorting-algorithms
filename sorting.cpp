// Сортування підрахунком мовою C++
#include <iostream>
#include <conio.h> // getch

#include <limits> // numeric_limits

#include "data.h"
#include "countingSort.h"
#include "radixSort.h"
#include "bucketSort.h"

using namespace std;

// Головне меню програми
void menu(int level, int algorithm) {

  //runCountingSort(3);
  //runRadixSort(3);
  //runBucketSort(8);

  int choice;

  // Головний рівень
  if (level==0) {
    cout << "--- MAIN MENU ---" << endl;
    cout << "Hello and welcome to a simple algorithm sorting programm. Choose your algorithm by entering it's number: " << endl;
    cout << "1. Counting sort " << endl;
    cout << "2. Radix sort" << endl;
    cout << "3. Bucket sort" << endl;
    cout << "4. Help" << endl;
    cout << "0. Exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin.clear();
    cin >> choice;
    cout << endl;
    switch(choice) {
      case 1:
        menu(1,1);
        break;
      case 0:
        cout << "See You!";
        exit(0);
      default:
        cout << "Command undefined" << endl;
        cout << "Press any key to go to MAIN MENU" << endl;
        getch();
        cout << endl;
        menu(0,0);
    }
  }

  // Меню алгоритму підрахунком
  if ((level==1)&&(algorithm==1)) {
    cout << "--- MAIN MENU / COUNTING SORT --- " << endl;
    cout << "Choose the mode of an algorithm:" << endl;    
    cout << "1. Random demo array 1000 ASC" << endl;
    cout << "10. Your array (random integers from 0 to 9)" << endl;
    cout << "0. Main menu" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin.clear();
    cin >> choice;
    cout << endl;

    switch(choice) {
      case 1:
        runCountingSort(1);        
        break;
      case 10:
        runCountingSort();
        break;
      case 0:
        menu(0,0);
        break;
      default:
        cout << "Command undefined" << endl;
        cout << "Press any key to go to MAIN MENU / COUNTING SORT" << endl;
        getch();
        cout << endl;
        menu(1,1);
    }

    cout << endl;
    cout << "Press any key to go to MAIN MENU / COUNTING SORT" << endl;
    getch();
    cout << endl;
    menu(1,1);
  }
  
}

// Головна функція
int main(void) {
  // Меню
  menu(0,0);

  // Запобігання передчасному закриттю консолі
  system("pause"); 
}
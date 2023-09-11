// Алгоритми сортування мовою C++
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

  int choice;

  // Головний рівень
  if (level==0) {
    cout << "--- MAIN MENU ---" << endl;
    cout << "Hello and welcome to a simple algorithm sorting programm. Choose your algorithm by entering its number: " << endl;
    cout << "1. Counting sort " << endl;
    cout << "2. Radix sort" << endl;
    cout << "3. Bucket sort" << endl;
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
      case 2:
        menu(1,2);
        break;
      case 3:
        menu(1,3);
        break;
      case 0:
        cout << "See You!";
        exit(0);
      default:
        cout << "Command undefined" << endl;
        cout << endl;
        cout << "Press any key to return" << endl;
        getch();
        cout << endl;
        menu(0,0);
    }
  }

  // Меню алгоритму підрахунком
  if (level==1) {
    if (algorithm==1) {
      cout << "--- MAIN MENU / COUNTING SORT ---" << endl;
    } else if (algorithm==2) {
      cout << "--- MAIN MENU / RADIX SORT ---" << endl;
    } else if (algorithm==3) {
      cout << "--- MAIN MENU / BUCKET SORT ---" << endl;
    }
    cout << "Choose the mode of an algorithm:" << endl;    
    cout << "1. Demo array 1000 ASC" << endl;
    cout << "2. Demo array 1000 DESC" << endl;
    cout << "3. Demo array 1000 random" << endl;
    cout << "4. Demo array 10000 ASC" << endl;
    cout << "5. Demo array 10000 DESC" << endl;
    cout << "6. Demo array 10000 random" << endl;
    cout << "7. Demo array 100000 ASC" << endl;
    cout << "8. Demo array 100000 DESC" << endl;
    cout << "9. Demo array 100000 random" << endl;
    if (algorithm==1) {
      cout << "10. Your array (random integers from 0 to 9)" << endl;
    } else if (algorithm==2) {
      cout << "10. Your array (random integers from 0 to 999)" << endl;
    } else if (algorithm==3) {
      cout << "10. Your array (random integers from 0 to 99)" << endl;
    }
    cout << "0. Main menu" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin.clear();
    cin >> choice;
    cout << endl;

    if ((choice >= 1) && (choice <= 10)) {
      if (algorithm==1) {
        runCountingSort(choice); 
      } else if (algorithm==2) {
        runRadixSort(choice); 
      } else if (algorithm==3) {
        runBucketSort(choice); 
      }        
    } else if (choice == 0) {
      menu(0,0);
    } else {
      cout << "Command undefined" << endl;
    }

    cout << endl;
    cout << "Press any key to return" << endl;
    getch();
    cout << endl;    
    menu(1,algorithm);
  }  

}

// Головна функція
int main(void) {
  // Меню
  menu(0,0);

  // Запобігання передчасному закриттю консолі
  system("pause"); 
}
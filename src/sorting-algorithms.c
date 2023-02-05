// Алгоритми сортування мовою C
#include <stdio.h>

// -------------------------------------------------------

// Алгоритм сортування підрахунком
void countingSort(int array[], int size) {

  // Ініціалізація вихідного масиву
  int output[size];
  
  // Пошук найбільшого елемента масиву
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Ініціалізація масиву з лічильниками розміром (max+1)
  int count[max + 1];

  // Заповнення масиву з лічильниками значеннями 0
  for (int i = 0; i <= max; i++) {
    count[i] = 0;
  }

  // Підрахунок кожного елемента вхідного масиву у відповідному індексі масиву лічильників
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Кумулятивна сума всіх попередніх значень в масиві лічильників
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Пошук індекса кожного елемента вхідного масива в масиві лічильників
  // Розміщення елементів в вихідний масив, декремент лічильника
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Перенос відсортованих значень у вхідний масив
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Вивід відсортованих даних
void printOutput(int array[], int size) {
  printf("Sorted data:\n");  
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);    
  }
  printf("\n");
}

// Перевірка розміру вхідного масиву
int sizeCheck() {
  int size;
  scanf("%d", &size);  
  if (size < 2) {
    printf("The number is too small, type a number from 2 to 10:\n");
    sizeCheck();
  } else if (size > 10) {
    printf("The number is too big, type a number from 2 to 10:\n");
    sizeCheck();
  } else {
    return size;  
  }
}

// Головне меню програми
void mainMenu(int level, int algorithm) {
  int choice;

  // Головний рівень
  if (level==0) {
    printf("Hello and welcome to simple algorithm sorting programm. Choose your algorithm by entering it's number \n");
    printf("1. Counting sort \n");
    printf("2. Radix sort\n");
    printf("3. Buchet sort\n");
    printf("4. Help\n");
    printf("5. Exit\n\n\n");
    printf("Enter your choice :  ");
    scanf("%d",&choice);
    switch(choice) {
      case 1:
        
        break;
      case 5:
        printf("See You!");
        exit(0);
      default:
        printf("Command undefined\n");
        printf("Press Any Key to Continue\n");
        getch();
        printf("\n");
        mainMenu(0,0);
    }
  }

  // Меню алгоритму підрахунком
  if ((level==1)&&(algorithm==1)) {

  }

  
  
  
}


// Головна функція
int main(void) {

  // Меню
  mainMenu(0,0);


  // -------------------------------------------------------

  // Ініціалізація та перевірка розміру вхідного масиву
  int size;
  
  printf("Enter the size of an array from 2 to 10: \n");
  size = sizeCheck();
  printf("The size or your input array is %d.\n", size);
  printf("Enter the value of each key. Value must be a non-negative integer.\n");

  // Ініціалізація та заповнення вхідного масиву
  int array[size];

  for (int i = 0; i < size; i++) {
    printf("Enter key %d of %d value: ", i + 1, size);
    scanf("%d", &array[i]);    
  }

  countingSort(array, size);
  printOutput(array, size); 

  // Запобігання передчасному закриттю консолі
  system("pause"); 
}
//T2

#include <iostream>
int main(){

    int min, max, p;
    std::cout << "Введіть мінімум: ";
    std::cin >> min;

    std::cout << "Введіть максимум: ";
    std::cin >> max;
     
     if (min>max){
      std::cout << "Введіть вірне значення!" << std::endl;
      return 1;
     }
     
    std::cout << "Введіть p: ";
    std::cin >> p;

    if (p >= min && p <= max) {
        std::cout << p << " належить " << min << " та " << max << "." << std::endl;
    }
     else {
        std::cout << p << " не належить " << min << " та " << max << "." << std::endl;

     }
}


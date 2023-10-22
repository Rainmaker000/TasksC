//t17

#include <iostream>
int main(){
    int number;
    int sum=0;
    bool negativefind=false;

    std::cout << "Введіть послідовність чисел(для завершення введіть від'ємне значення: " << std::endl;
    while(true){
        std::cin >> number;

        if(number<0){
        negativefind=true;
        break;
    }

    sum += number;
    }

    if(negativefind){
       std::cout << "Сума всіх додатніх чисел перед від'ємними = " << sum << std::endl;
    } 
    }

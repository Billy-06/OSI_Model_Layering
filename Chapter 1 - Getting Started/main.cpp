// Author: Billy Micah
// Created by User on 5/10/2021.
// Description: Introductory program in C++

/*                      [Quick Read]
 * WHAT:  PREPROCESSOR DIRECTIVES
 * WHY:
 * WHEN:
 * HOW:
 * WHERE(where applicable):
 *
 * */


#include <iostream>
#include <cstdio>
#include <typeinfo>

void usingSTL(){
    int newNum;
    std::string yourName;
    char greetingMessage[] = "Welocome to Leaning C++. We'll start with some simple variables";
    short birthYear;
    long earthCircumference{ 40075017L } ;
    double pieRatesOfTheCarribean[] {4.50, 5.50, 3.50, 2.20, 6.50};

    std::cout << greetingMessage << std::endl;
    std::cout << "What is your year of birth?" << std::endl;
    do {
        std::cin >> birthYear;
        if (typeid(birthYear) != int16_t)
        {
            std::cout << "Please enter and integer. Thanks" << std::endl;
        }
        else
            break;
    } while (true);
    std::cout << "Please enter your fullname" << std::endl;
    do {
        std::cin.getline(yourName);
        if (typeid(yourName) != std::string) 
        {
            std::cout << "Please use words to type your name" << std::endl;
        } 
        else 
            break;
    } while (true);
    

    std::cout << "Great, the value you entered is type: " << typeid(birthYear) 
            << "and occupied " << sizeof(birthYear) << " bytes" << std::endl;
    std::cout << "Our greating from earlier was type: " << typeid(greetingMessage) 
            << " and occupied " << sizeof(greetingMessage) << std::endl;
    std::cout << "The earth's Circumference of value, " << earthCircumference 
            << " is type: " << typeid(greetingMessage) << " and occupied " 
            << sizeof(greetingMessage) << std::endl;
}



void soMathematical(){
    double myPiValue, myGravityValue;
    char yourAnswer;

    puts("Do you like mathematics\n");
    printf("Did you know the %d^2 would give you %d?", myPiValue, myGravityValue);
    puts("Do you recognize any of those values?\nWhat do they represent?\n");
    
    
    do
    {
        puts("Give your answer  in lowercase in the format: value value\nSeparating\
         your answers using a single space character\n");
        scanf_s("%c\n", yourAnswer);
        if (yourAnswer != "pi gravity"){
            puts("You go it wrong. Please try again.");
        } else break;

    } while (true);
    
    


}

int main(){
    usingSTL();


    return 0;
}


#include <iostream>
#include <cstdio>
#include <typeinfo>

template <typename T>
bool intValidate(T& item);

template <typename T>
bool shortValidate(T& item);

template <typename T>
bool stringValidate(T& item);

template <typename T>
bool intValidate(T& item){
    int someInt{ 45 };
    const std::type_info& inputType = typeid(item);
    const std::type_info& checker = typeid(someInt);

    if (checker.hash_code() != inputType.hash_code()){
        puts("The value you entered is type: %s", typeid(item).name());
        puts("However you were meant to input a type: %s", typeid(someInt).name());
        return false;
    } 
    else if (checker.type_index() == inputType.type_index()){
        return true;
    } 
    else {
        puts("Couldn't validate the type of the input");
        return false;
    }


}

template <typename T>
bool shortValidate(T& item){
    uint16_t someShort{ 1548 };
    const std::type_info& inputName = typeid(item);
    const std::type_info& checker = typeid(someShort);

    if (checker.hash_code() != inputName.hash_code()){
        puts("The value you entered is type: %s", typeid(item).name());
        puts("However you were meant to input a type: %s", typeid(someShort).name());
        return false;
    }
    else if (checker.type_index() == inputName.type_index()){
        return true;
    }
    else {
        puts("Couldn't validate the type of the input");
        return false;
    }

}

template <typename T>
bool stringValidate(T& item){
    std::string myStr{ "This is a string "};
    const std::type_info& inputName = typeid(item);
    const std::type_info& checker = typeid(myStr);
    

    if (checker.hash_code() != myStr.hash_code()){
        puts("The value you entered was type: %s", typeid(item).name());
        puts("However you were meant to input a type: %s". typeid(myStr).name());
        return false;
    } 
    else if (checker.type_index() == inputName.type_index()){
        return true;
    }
    else {
        puts("Couldn't validate the type of the input");
        return false;
    }

}
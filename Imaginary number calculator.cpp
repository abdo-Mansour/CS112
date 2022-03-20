#include <iostream>
#include <string>
#include <complex>

int main(){
    double first_real, first_imag, second_real, second_image;//this should define each part of the numbers
    std::string operation;

    std::cout << "Please enter the number in order first-real first-imaginary operation second-real second-imaginary\n";
    std::cout << "For example: 1 2 * 2 4.\n";
    std::cout << "equation: ";

    std::cin >> first_real >> first_imag >> operation >> second_real >> second_image;
    std::complex<double> first_complete(first_real, first_imag), second_complete(second_real, second_image);
    //now we will deal with operations
    if(operation == "+"){
        std::cout << first_complete + second_complete << "\n";
    }
    else if(operation == "-"){
        std::cout << first_complete - second_complete << "\n";
    }
    else if(operation == "*"){
        std::cout << first_complete * second_complete << "\n";
    }
    else if(operation == "/"){
        std::cout << first_complete / second_complete << "\n";
    }
}
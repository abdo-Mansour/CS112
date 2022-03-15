// FCAI - Programming 1 - 2022 - Assignment 2
// Program Name: Morse code encryption
// Program description: This program should take input roman Letters and convert them to morse code and vice versa.
// Last modification date: 15/3/2022
// Created by Adham Mansour(20210057) Group A

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//defining constants
//this should define the letters and their corresponding morse code in separate variables letters and morse.
char text[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

string morse[36] = {".-","-...","-.-.","-..",".","..-","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",
                    ".----","..---","...--","....-",".....","-....","--....","---..","----.","-----"};

void text_to_morse() {

    string letters;

    cout << "Please enter the letters: ";

    getline(cin, letters); //this should get inputs separated by spaces and store them in "letters" variable
    transform(letters.begin(), letters.end(), letters.begin(), ::toupper); //this should convert all the letters to capital letters
    cout << endl <<"Converted morse code: ";

    for(int i = 0; i < letters.length(); i++){

        for(int k = 0; k < 36;k++){

            if(letters.at(i) == text[k]){

                cout << morse[k] << " ";

            }
        }
        if(isspace(letters.at(i))){
            cout << "   ";
        }
    }
    cout << endl;
}

void morse_to_text() {
    string morse_code, temp_code;

    cout << "Please enter the code: ";
    getline(cin, morse_code);

    cout << "Converted text: ";

    for(int i = 0; i <= morse_code.length();i++){

        if(morse_code[i] != ' '){
            temp_code += morse_code[i];
        }

        else if(morse_code[i] == ' '){

            for(int k = 0;k < 36;k++){

                if(temp_code == morse[k]){
                    cout << text[k];
                }
            }
            temp_code = "";
        }

    }
}
// still remaining to solve the last letter bug and identify a condifition to separate words and not only letters in morse_to_Text function

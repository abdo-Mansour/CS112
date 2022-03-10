//This is subtracting a square game
// Created by Adham mansour(20210057) on 2/24/2022.

#include <iostream>
#include <list>
#include<bits/stdc++.h>

using namespace std;

int max_no_of_tokens = 50;
std::list<int> squared_numbers = {};

void generating_numbers(){ // this should generate the numbers and store them in a list
    int i = 1;
    while (i * i <= max_no_of_tokens){
        squared_numbers.push_back(i * i);
        i++;
    }

}

void printing_the_list(){ // this should print the number in the list to be used after every move
    for (int x : squared_numbers) {
        cout << x << ' ';
    }
    cout << endl;
}


void choosing_numbers(){ // This is where the real fun begins

    cout << "The number of tokens is: " << max_no_of_tokens << endl;

    int number_of_player_1, number_of_player_2;

    for(int k = 0; k <= squared_numbers.size(); k++) { //this is where the real game starts
        cout << "Player 1 : Please enter the number: ";
        cin >> number_of_player_1;

        if (bool (std::find(squared_numbers.begin(), squared_numbers.end(), number_of_player_1) !=
                          squared_numbers.end())) { // this should check if the number entered exists in the list or not
            squared_numbers.remove(number_of_player_1);
            max_no_of_tokens-= number_of_player_1;
        }
        else {
            cout << "Number doesn't exist enter another number: ";
            cin >> number_of_player_1;
            squared_numbers.remove(number_of_player_1);
            max_no_of_tokens-= number_of_player_1;
        }
        if (max_no_of_tokens == 0) { // this should decide on the winner
            cout << "Player 1 wins" << endl;
            break;
        }

        cout << "The remaining tokens: " << max_no_of_tokens << endl;

        cout << "Player 2 : Please enter the number: "; //same procedure as before but with player 2
        cin >> number_of_player_2;

        if (bool (std::find(squared_numbers.begin(), squared_numbers.end(), number_of_player_2) !=
                          squared_numbers.end())) {
            squared_numbers.remove(number_of_player_2);
            max_no_of_tokens-= number_of_player_2;
        }
        else {
            cout << "Number doesn't exist enter another number: ";
            cin >> number_of_player_2;
            squared_numbers.remove(number_of_player_2);
            max_no_of_tokens-= number_of_player_1;
        }
        if (max_no_of_tokens == 0) {
            cout << "Player 2 wins" << endl;
            break;
        }
        cout << "The remaining tokens: " << max_no_of_tokens << endl;
    }
}

int main(){ // this should recall all the game functions
    generating_numbers();
    choosing_numbers();

}

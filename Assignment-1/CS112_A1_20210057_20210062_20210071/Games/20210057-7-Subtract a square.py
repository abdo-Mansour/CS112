# This is subtracting a square game
# Author : Adham mansour (20210057)
# Date : 24/2/2022
import math

no_of_tokens = 50  # just random number of tokens
squared_numbers = []


def generating_numbers():  # this should generate all the squared numbers from 0 to number of tokens
    i = 1
    while i ** 2 <= no_of_tokens:
        squared_numbers.append(i ** 2)
        i += 1


def choosing_numbers():  # this is where the real game starts
    global no_of_tokens

    print("The number of tokens is ", no_of_tokens)

    for k in range(math.ceil(no_of_tokens / 2)):  # the math function is used here to round up the fraction if the
        # number of tokens is odd
        number_of_player1 = int(input("Player 1: Please enter number: "))
        while number_of_player1 not in squared_numbers:  # this should check if the number given is squared
            print("number doesn't exist")
            number_of_player1 = int(input("Please enter number: "))
        no_of_tokens -= number_of_player1
        if no_of_tokens == 0:  # this should check if first player won the game if the list is empty
            print("Player 1 wins")
            break
        print("Remaining: ", no_of_tokens)
        number_of_player2 = int(input("Player 2: Please enter number: "))
        while number_of_player2 not in squared_numbers:
            print("number doesn't exist")
            number_of_player2 = int(input("Please enter number: "))
        no_of_tokens -= number_of_player2
        if no_of_tokens == 0:
            print("Player 2 wins")
            break
        print("Remaining: ", no_of_tokens)


def all_game():
    generating_numbers()
    choosing_numbers()


all_game()

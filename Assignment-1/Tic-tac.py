# This is tic tac toe game with numbers
# Created by Mansour on 27/2/2003
# CS112 Assignment 1 Task 1 Question 2

import numpy as np


def init_board():  # this should initialize data of the board
    board = np.empty(shape=(3, 3), dtype="int")
    for r in range(3):
        for c in range(3):
            board[r] = 0
    return board


# this should print a 3x3 grid
def draw_board():
    print(board[0][0], '|', board[0][1], '|', board[0][2])
    print("----------")
    print(board[1][0], '|', board[1][1], '|', board[1][2])
    print("----------")
    print(board[2][0], '|', board[2][1], '|', board[2][2])


board = init_board()


# this should take input from the 2 players
def is_empty(row, column):
    return board[row][column] == 0


player_1_numbers = [1, 3, 5, 7, 9]  # This should define the number valid for the first player
player_2_numbers = [0, 2, 4, 6, 8]  # This should define the number valid for the second player


# This should take input from the first player and check it's conditions
def taking_input_from_player1():
    row = int(input("Player 1 Please enter a row (1-3): ")) - 1
    column = int(input("Player 1 Please enter a column (1-3): ")) - 1
    while not is_empty(row, column):
        print("the location is not valid")
        row = int(input("Player 1 Please enter a row (1-3): ")) - 1
        column = int(input("Player 1 Please enter a column (1-3): ")) - 1
    piece = int(input("Please enter the odd number: "))
    while piece not in player_1_numbers:
        print("invalid number")
        piece = int(input("Please enter the odd number: "))
    update_board(row, column, piece)


# same here as player 2
def taking_input_from_player2():
    row = int(input("Player 2 Please enter a row (1-3): ")) - 1
    column = int(input("Player 2 Please enter a column (1-3): ")) - 1
    piece = int(input("Please enter the even number"))
    while piece not in player_2_numbers:
        print("invalid number")
        piece = int(input("Please enter the even number:    "))
    while not is_empty(row, column):
        print("the location is not valid")
        row = int(input("Player 2 Please enter a row (1-3): ")) - 1
        column = int(input("Player 2 Please enter a column (1-3): ")) - 1
    update_board(row, column, piece)


def update_board(row, column, piece):  # thos should update the board until the latest update
    board[row][column] = piece


def check_winner():  # this should decide on the winner
    # this should check the horizontal
    for i in range(0, 3):
        if board[i][0] + board[i][1] + board[i][2] == 15:
            return True
    # this should check the vertical
    for k in range(0, 3):
        if board[0][k] + board[1][k] + board[2][k] == 15:
            return True
    # this should the check the first diagonal
    if board[0][0] + board[1][1] + board[2][2] == 15:
        return True
    # this should check the second diagonal
    elif board[0][2] + board[1][1] + board[2][0] == 15:
        return True


def whole_game():  # this should put all the game together
    draw_board()
    for c in range(5):
        taking_input_from_player1()
        if check_winner():
            print("Player 1 is the winner")
            break
        draw_board()
        taking_input_from_player2()
        if check_winner():
            print("Player 2 is the winner")
            break
        draw_board()


whole_game()
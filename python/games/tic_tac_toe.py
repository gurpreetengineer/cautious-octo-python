# Tic Tac Toe game in Python

board = [' ' for x in range(10)]


def insertLetter(letter, pos):
    board[pos] = letter


def spaceIsFree(pos):
    return board[pos] == ' '


def printBoard(board):
    print('   |   |')
    print(' ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[7] + ' | ' + board[8] + ' | ' + board[9])
    print('   |   |')


def isWinner(bo, le):
    return (bo[7] == le and bo[8] == le and bo[9] == le) or \
           (bo[4] == le and bo[5] == le and bo[6] == le) or \
           (bo[1] == le and bo[2] == le and bo[3] == le) or \
           (bo[7] == le and bo[4] == le and bo[1] == le) or \
           (bo[8] == le and bo[5] == le and bo[2] == le) or \
           (bo[9] == le and bo[6] == le and bo[3] == le) or \
           (bo[7] == le and bo[5] == le and bo[3] == le) or \
           (bo[9] == le and bo[5] == le and bo[1] == le)


def playerMove():
    run = True
    while run:
        move = input("Please select a position to place an 'X' (1-9): ")
        try:
            move = int(move)
            if move > 0 and move < 10:
                if spaceIsFree(move):
                    run = False
                    insertLetter('X', move)
                else:
                    print("Sorry, this space is occupied!")
            else:
                print("Please type a number within the range!")
        except:
            print("Please type a number!")


def compMove():
    possibleMoves = [x for x, letter in enumerate(board) if letter == ' ' and x != 0]
    move = 0

    for let in ['O', 'X']:
        for i in possibleMoves:
            boardCopy = board[:]
            boardCopy[i] = let
            if isWinner(boardCopy, let):
                move = i
                return move

    cornersOpen = []
    for i in possibleMoves:
        if i in [1, 3, 7, 9]:
            cornersOpen.append(i)

    if len(cornersOpen) > 0:
        move = selectRandom(cornersOpen)
        return move

    if 5 in possibleMoves:
        move = 5
        return move

    edgesOpen = []
    for i in possibleMoves:
        if i in [2, 4, 6, 8]:
            edgesOpen.append(i)

    if len(edgesOpen) > 0:
        move = selectRandom(edgesOpen)

    return move


def selectRandom(lst):
    import random
    length = len(lst)
    rand_index = random.randrange(0, length)
    return lst[rand_index]
  
  def check_win(board, player):
    if (board[0] == player and board[1] == player and board[2] == player) or \
       (board[3] == player and board[4] == player and board[5] == player) or \
       (board[6] == player and board[7] == player and board[8] == player) or \
       (board[0] == player and board[3] == player and board[6] == player) or \
       (board[1] == player and board[4] == player and board[7] == player) or \
       (board[2] == player and board[5] == player and board[8] == player) or \
       (board[0] == player and board[4] == player and board[8] == player) or \
       (board[2] == player and board[4] == player and board[6] == player):
        return True
    else:
        return False

def check_tie(board):
    for i in range(9):
        if board[i] == ' ':
            return False
    return True

def get_move(board, player):
    valid_move = False
    while not valid_move:
        move = input(f"{player}, enter your move (1-9): ")
        if move not in ['1', '2', '3', '4', '5', '6', '7', '8', '9']:
            print("Invalid input. Please enter a number between 1 and 9.")
            continue
        move = int(move) - 1
        if board[move] != ' ':
            print("That square is already occupied. Please choose another.")
            continue
        valid_move = True
    return move

def tic_tac_toe():
    print("Welcome to Tic Tac Toe!")
    board = [' '] * 9
    player = 'X'
    while True:
        print_board(board)
        move = get_move(board, player)
        board[move] = player
        if check_win(board, player):
            print_board(board)
            print(f"{player} wins!")
            break
        elif check_tie(board):
            print_board(board)
            print("Tie game!")
            break
        if player == 'X':
            player = 'O'
        else:
            player = 'X'

tic_tac_toe()

  

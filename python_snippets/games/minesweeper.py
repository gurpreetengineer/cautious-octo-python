import random

class Minesweeper:
    def __init__(self, rows, cols, mines):
        self.rows = rows
        self.cols = cols
        self.mines = mines
        self.grid = [[0 for _ in range(cols)] for _ in range(rows)]
        self.mask = [['-' for _ in range(cols)] for _ in range(rows)]
        self.generate_board()

    def generate_board(self):
        mines_placed = 0
        while mines_placed < self.mines:
            row, col = random.randint(0, self.rows - 1), random.randint(0, self.cols - 1)
            if self.grid[row][col] != -1:
                self.grid[row][col] = -1
                mines_placed += 1
                for i in range(max(0, row - 1), min(row + 2, self.rows)):
                    for j in range(max(0, col - 1), min(col + 2, self.cols)):
                        if self.grid[i][j] != -1:
                            self.grid[i][j] += 1

    def display_board(self):
        print("   " + " ".join(str(i) for i in range(self.cols)))
        print("  " + "-" * (2 * self.cols - 1))
        for row in range(self.rows):
            print(str(row) + " |" + " ".join(str(self.mask[row][col]) for col in range(self.cols)) + "|")

    def reveal_board(self, row, col):
        if self.grid[row][col] == -1:
            return False
        self.mask[row][col] = str(self.grid[row][col])
        if self.grid[row][col] == 0:
            for i in range(max(0, row - 1), min(row + 2, self.rows)):
                for j in range(max(0, col - 1), min(col + 2, self.cols)):
                    if self.mask[i][j] == '-' and (i != row or j != col):
                        self.reveal_board(i, j)
        return True

    def play(self):
        game_over = False
        self.display_board()
        while not game_over:
            row = int(input("Enter row: "))
            col = int(input("Enter column: "))
            if self.reveal_board(row, col):
                self.display_board()
                if all('-' not in row for row in self.mask):
                    print("Congratulations! You have won the game.")
                    game_over = True
            else:
                print("Game over! You have hit a mine.")
                self.display_board()
                game_over = True

# Example usage:
game = Minesweeper(10, 10, 15)
game.play()



# In this implementation, the game board is represented by a 2D list called grid, where -1 represents a mine and 
# each non-negative integer represents the number of mines in the surrounding cells. 
# 
# The mask list is used to keep track of which cells have been revealed and which are still hidden. 
# The generate_board method randomly places the specified number of mines on the board and 
# calculates the number of mines in the surrounding cells. 
# 
# The display_board method prints out the current state of the board. 
# The reveal_board method is used to reveal a cell, and if the revealed cell is empty, 
# it recursively reveals all the neighboring cells until no more empty cells are left. 
# 
# Finally, the play method is the main game loop that prompts the user for input and reveals the cell if it is safe

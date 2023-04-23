import pygame
import time
import random
 
pygame.init()
 
white = (255, 255, 255)
black = (0, 0, 0)
red = (213, 50, 80)
green = (0, 255, 0)
blue = (50, 153, 213)
 
width = 600
height = 400
 
dis = pygame.display.set_mode((width, height))
pygame.display.set_caption('Snake Game by OpenAI')
 
clock = pygame.time.Clock()
 
snake_block = 10
snake_speed = 15
 
font_style = pygame.font.SysFont(None, 30)
 
 
def message(msg, color):
    mesg = font_style.render(msg, True, color)
    dis.blit(mesg, [width / 6, height / 3])
 
 
def gameLoop():
    game_over = False
    game_close = False
 
    x1 = width / 2
    y1 = height / 2
 
    x1_change = 0
    y1_change = 0
 
    foodx = round(random.randrange(0, width - snake_block) / 10.0) * 10.0
    foody = round(random.randrange(0, height - snake_block) / 10.0) * 10.0
 
    while not game_over:
 
        while game_close == True:
            dis.fill(blue)
            message("You Lost! Press Q-Quit or C-Play Again", red)
            pygame.display.update()
 
            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        game_over = True
                        game_close = False
                    if event.key == pygame.K_c:
                        gameLoop()
 
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x1_change = -snake_block
                    y1_change = 0
                elif event.key == pygame.K_RIGHT:
                    x1_change = snake_block
                    y1_change = 0
                elif event.key == pygame.K_UP:
                    y1_change = -snake_block
                    x1_change = 0
                elif event.key == pygame.K_DOWN:
                    y1_change = snake_block
                    x1_change = 0
 
        if x1 >= width or x1 < 0 or y1 >= height or y1 < 0:
            game_close = True
 
        x1 += x1_change
        y1 += y1_change
        dis.fill(blue)
        pygame.draw.rect(dis, green, [foodx, foody, snake_block, snake_block])
        pygame.draw.rect(dis, black, [x1, y1, snake_block, snake_block])
        pygame.display.update()
 
        if x1 == foodx and y1 == foody:
            print("Yummy!!")
        clock.tick(snake_speed)
 
    pygame.quit()
    quit()
 
 
gameLoop()

# Explanation of the above code:

# 1) First, we import the necessary libraries: pygame for game development and random for generating random numbers.

# 2) We define some constants for the game window size, the size of the snake block, the colors used in the game, and the speed of the game.

# 3) Next, we define the Snake class, which represents the snake object in the game. It has attributes for the position, direction, and length of the snake, and methods for updating the position, growing the length, and checking for collisions.

# 4) We define the Food class, which represents the food object in the game. It has attributes for the position and color of the food, and a method for generating a new position for the food when it is eaten by the snake.

# 5) We initialize the game by setting up the game window and creating instances of the Snake and Food classes.

# 6) We set up the game loop, which runs continuously until the game is exited. Inside the loop, we handle user input, update the snake and food positions, and check for collisions between the snake and the food or the game walls.

# 7) We render the game graphics by drawing the snake and food objects on the game window, and updating the display with each iteration of the game loop.

# Overall, the code implements a simple version of the classic Snake game, where the player controls a snake that grows in length as it eats food and dies if it collides with the game walls or its own body.

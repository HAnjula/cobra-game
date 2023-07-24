#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define GRID_SIZE 20
#define CELL_SIZE 2

struct Snake
{
    int x, y;
    int bodyX[GRID_SIZE * GRID_SIZE];
    int bodyY[GRID_SIZE * GRID_SIZE];
};

struct Food
{
    int x, y;
};

struct Snake snake;
struct Food food;
int direction;
int gameOver;
int length = 3;
int score = 0;

void SetupGame()
{
    snake.x = GRID_SIZE / 2;
    snake.y = GRID_SIZE / 2;

    food.x = rand() % GRID_SIZE;
    food.y = rand() % GRID_SIZE;

    direction = 1;
    gameOver = 0;
}

void HandleInput()
{
    if (_kbhit())
    {
        char ch = _getch();
        switch (ch)
        {
        case 'w':
        case 'W':
            if (direction != 2)
                direction = 0;
            break;
        case 'd':
        case 'D':
            if (direction != 3)
                direction = 1;
            break;
        case 's':
        case 'S':
            if (direction != 0)
                direction = 2;
            break;
        case 'a':
        case 'A':
            if (direction != 1)
                direction = 3;
            break;
        case 'q':
        case 'Q':
            gameOver = 1;
            break;
        }
    }
}

void Update()
{
    switch (direction)
    {
    case 0:
        snake.y--;
        break;
    case 1:
        snake.x++;
        break;
    case 2:
        snake.y++;
        break;
    case 3:
        snake.x--;
        break;
    }

    // Increase the snake's length
    if (snake.x == food.x && snake.y == food.y)
    {
        length++;
        score += 10;

        // Move the food to a new random position
        food.x = rand() % GRID_SIZE;
        food.y = rand() % GRID_SIZE;
    }

    // Check for collisions with the window boundaries
    if (snake.x < 0 || snake.x >= GRID_SIZE || snake.y < 0 || snake.y >= GRID_SIZE)
    {
        gameOver = 1;
    }

    // Check for collisions with the snake's body
    for (int i = 1; i < length; i++)
    {
        if (snake.x == snake.bodyX[i] && snake.y == snake.bodyY[i])
        {
            gameOver = 1;
            break;
        }
    }

    // Move the rest of the snake's body
    for (int i = length - 1; i > 0; i--)
    {
        snake.bodyX[i] = snake.bodyX[i - 1];
        snake.bodyY[i] = snake.bodyY[i - 1];
    }

    // Update the position of the snake's head in the body array
    snake.bodyX[0] = snake.x;
    snake.bodyY[0] = snake.y;
}

void Draw()
{
    system("cls"); // Clear the terminal

    // Draw the top border
    for (int i = 0; i < GRID_SIZE + 22; i++)
    {
        putchar('-');
    }
    putchar('\n');

    // Draw the game grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        putchar('|'); // Left border
        for (int j = 0; j < GRID_SIZE+22; j++)
        {
            if (i == snake.y && j == snake.x)
                putchar('O'); // Snake's head
            else if (i == food.y && j == food.x)
                putchar('@'); // Food
            else
            {
                int isBodyPart = 0;
                for (int k = 0; k < length; k++)
                {
                    if (i == snake.bodyY[k] && j == snake.bodyX[k])
                    {
                        isBodyPart = 1;
                        break;
                    }
                }
                putchar(isBodyPart ? '0' : ' '); // Snake's body or empty cell
            }
        }
        putchar('|'); // Right border
        putchar('\n');
    }

    // Draw the bottom border
    for (int i = 0; i < GRID_SIZE + 22; i++)
    {
        putchar('-');
    }
    putchar('\n');


    // Display the score
    printf("Score: %d\n", score);
}

int main()
{
    srand(time(NULL));

    SetupGame();

    // Game loop
    while (!gameOver)
    {
        HandleInput();
        Update();
        Draw();
        Sleep(150);
    }

    printf("Game Over!\n");
    printf("Your score: %d\n", score);

    return 0;
}

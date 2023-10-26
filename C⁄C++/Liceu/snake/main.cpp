#include <iostream>
#include <conio.h>
#include <windows.h>

void run();
void printMap();
void initMap();
void move(int dx, int dy);
void update();
void changeDirection(char key);
void clearScreen();
void generateFood();

char getMapValue(int value);

// Map dimensions
const int MapWidth = 20;
const int MapHeight = 20;

// The tile values for the map
int m[MapHeight][MapWidth];

// Snake head details
int xCap;
int yCap;
int direction;

// Amount of food the snake has (How long the body is)
int food = 3;

// Determine if game is running
bool running;

int main()
{
  run();
  return 0;
}

// Main game function
void run()
{
    int a=4, q=500;
  // Initialize the map
  initMap();
  running = true;
  while (running) {
        while(food >= a and q >= 200){
            q -= 200;
            a++;
        }
    // If a key is pressed
    if (kbhit()) {
      // Change to direction determined by key pressed
      changeDirection(getch());
    }
    // Upate the map
    update();
    // Clear the screen
    clearScreen();
    // Print the map
    printMap();
    // wait 0.5 seconds
    Sleep(q);
  }
  // Print out game over text
  std::cout << "\t\t!!!Game over!" << std::endl << "\t\tYour score is: " << food;
  // Stop console from closing instantly
  std::cin.ignore();
}

// Changes snake direction from input
void changeDirection(char key) {
  /*
    W
  A + D
    S

    1
  4 + 2
    3
  */
  switch (key) {
    case 'w':
      if (direction != 2) direction = 0;
      break;
    case 'd':
      if (direction != 3) direction = 1;
      break;
    case 's':
      if (direction != 4 and direction != 0) direction = 2;
      break;
    case 'a':
      if (direction != 5 and direction != 1) direction = 3;
      break;
  }
}

// Moves snake head to new location
void move(int dx, int dy) {
  // determine new head position
  int newx = xCap + dx;
  int newy = yCap + dy;
  // Check if there is food at location
  if (m[newx][newy] == -2) {
    // Increase food value (body length)
    food++;
    // Generate new food on map
    generateFood();
  }
  // Check location is free
  else
    if (m[newx][newy] != 0) {
      running = false;
    }
  // Move head to new location
  xCap = newx;
  yCap = newy;
  m[xCap][yCap] = food + 1;
}

// Clears screen
void clearScreen() {
  // Clear the screen
  system("cls");
}

// Generates new food on map
void generateFood() {
  int x = 0;
  int y = 0;
  do {
    // Generate random x and y values within the map
    x = rand() % (MapWidth - 2) + 1;
    y = rand() % (MapHeight - 2) + 1;
    // If location is not free try again
  } while (m[x][y] != 0);
  // Place new food
  m[x][y] = -2;
}

// Updates the map
void update() {
  // Move in direction indicated
  switch (direction) {
    case 0: move(-1, 0);
      break;
    case 1: move(0, 1);
      break;
    case 2: move(1, 0);
      break;
    case 3: move(0, -1);
      break;
  }
  // Reduce snake values on map by 1
  for (int ix = 0; ix < MapHeight; ix++) {
    for (int iy = 0; iy < MapWidth; iy++) {
      if (m[ix][iy] > 0)
        m[ix][iy]--;
    }
  }
}

// Initializes map
void initMap()
{
  // Places the initual head location in middle of map
  xCap = MapWidth / 2;
  yCap = MapHeight / 2;
  m[xCap][yCap] = 1;
  // Places top and bottom walls
  for (int x = 0; x < MapWidth; x++) {
    m[x][0] = -1;
    m[x][MapHeight - 1] = -1;
  }
  // Places left and right walls
  for (int y = 0; y < MapHeight; y++) {
    m[0][y] = -1;
    m[MapWidth - 1][y] = -1;
  }
  // Generates first food
  generateFood();
}

// Prints the map to console
void printMap()
{
  for (int x = 0; x < MapWidth; x++) {
    for (int y = 0; y < MapHeight; y++) {
      // Prints the value at current x,y location
      std::cout << getMapValue(m[x][y]);
    }
    // Ends the line for next x value
    std::cout << std::endl;
  }
}

// Returns graphical character for display from map value
char getMapValue(int value)
{
  // Returns a part of snake body
  if (value > 0) return 'o';
  switch (value) {
    // Return wall
    case -1: return 'X';
    // Return food
    case -2: return 'O';
  }
}

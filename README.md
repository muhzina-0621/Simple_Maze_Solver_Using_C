
# Simple_Maze_Solver_Using_C

This program generates and solves a random maze using a stack-based backtracking approach. Here is a brief description of its components and functionality:

1. **Definitions and Global Variables:**
   - `#define MAX_N 100`: Sets the maximum maze size to 100x100.
   - `int N`: Holds the actual size of the maze entered by the user.
   - `int maze[MAX_N][MAX_N]`: Represents the maze grid where 0 is a path and 1 is a wall.
   - `int solution[MAX_N][MAX_N]`: Stores the solution path of the maze.

2. **Node Structure for Stack:**
   - `typedef struct Node`: Defines a stack node containing x and y coordinates and a pointer to the next node.
   - `Node *top = NULL`: Initializes the top of the stack.

3. **Stack Operations:**
   - `void push(int x, int y)`: Pushes a new node onto the stack with coordinates `(x, y)`.
   - `void pop()`: Removes the top node from the stack.

4. **Maze Printing:**
   - `void printMaze(int start_x, int start_y, int end_x, int end_y)`: Prints the maze with 'S' for the start point, 'E' for the end point, '#' for walls, and spaces for paths.

5. **Maze Generation:**
   - `void generateRandomMaze(int start_x, int start_y, int end_x, int end_y)`: Generates a random maze ensuring higher probability for open paths and guarantees that the start and end points are open.

6. **Maze Solving:**
   - `int isSafe(int x, int y)`: Checks if a cell `(x, y)` is within the maze bounds and is a path (not a wall).
   - `int solveMaze(int start_x, int start_y, int end_x, int end_y)`: Uses backtracking with a stack to solve the maze. It pushes the start point onto the stack, explores adjacent cells, and backtracks if a dead-end is reached. If the end point is reached, the function returns success.

7. **Main Function:**
   - Takes maze size and start/end points as input from the user.
   - Generates and prints the random maze.
   - Attempts to solve the maze and prints the solution path if one exists, or a message if no solution is found.

### Program Flow:

1. **Input:**
   - User inputs the size of the maze and coordinates for the start and end points.

2. **Maze Generation:**
   - A random maze is generated with more open paths.

3. **Maze Printing:**
   - The initial maze is printed.

4. **Maze Solving:**
   - The maze is solved using a stack-based backtracking approach.
   - If a solution is found, it prints the maze with the solution path marked.
   - If no solution exists, it notifies the user.

This program illustrates a simple implementation of maze generation and solving using basic data structures and algorithms in C.






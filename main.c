#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 100 // Maximum size of the maze

int N; // Size of the maze
int maze[MAX_N][MAX_N];
int solution[MAX_N][MAX_N];



typedef struct Node {
	int x_cord,y_cord;
    struct Node* next;
} Node;

Node *top=NULL;


void push(int x,int y) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->x_cord = x;
    t->y_cord=y;
    t->next = top;
    top=t;
}


void pop() {
    if (top == NULL) {
       // Stack is empty
    }
 Node* temp = top;
    top = top->next;
    free(temp);
    
}

// Function to print the maze
void printMaze(int start_x,int start_y, int end_x,int end_y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == start_x && j == start_y)
                printf("S "); // Starting point
            else if (i == end_x && j == end_y)
                printf("E "); // Ending point
            else if (maze[i][j] == 1)
                printf("# "); // Wall
            else
                printf("  "); // Path
        }
        printf("\n");
    }
}

// Function to check if (x, y) is a valid cell
int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}

// Function to generate a random maze with a higher probability of open paths
void generateRandomMaze(int start_x,int start_y,int end_x,int end_y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
    
            maze[i][j] = (rand() % 100 < 80) ? 0 : 1;
        }
    }
    
    // Ensure the start and end points are open
    maze[start_x][start_y] = 0;
    maze[end_x][end_y] = 0;
}

// Function to solve the maze using backtracking and a linked list stack
int solveMaze(int start_x,int start_y,int end_x,int end_y) {
    
    push(start_x,start_y); // Push the starting point onto the stack

    while (top != NULL) {
        int current_x = top->x_cord;
        int current_y = top->y_cord;
        pop();

        if (current_x == end_x && current_y == end_y) {
            // Maze solved
            solution[current_x][current_y] = 1;
            free(top); // Free the remaining stack
            return 1;
        }

        if (isSafe(current_x, current_y)) {
            solution[current_x][current_y] = 1;

            // Push adjacent cells onto the stack
            if (current_y + 1 < N)
                 push(current_x, current_y + 1); // Right
            if (current_x + 1 < N)
                push(current_x + 1, current_y); // Down
        }
    }

    return 0; // No solutionvf
}
int main() {
    srand(time(NULL));

    printf("Enter the size of the maze (N x N): ");
    scanf("%d", &N);

    int start_x,start_y,end_x,end_y;

    printf("Enter the starting point (x y): ");
    scanf("%d %d", &start_x, &start_y);

    printf("Enter the ending point (x y): ");
    scanf("%d %d", &end_x, &end_y);

    if (start_x < 0 || start_y < 0 || end_x < 0 || end_y < 0 || start_x >= N || start_y >= N || end_x >= N || end_y >= N) {
        printf("Invalid starting or ending point. Exiting...\n");
        return 1;
    }

    generateRandomMaze(start_x,start_y,end_x,end_y);

    printf("Random Maze:\n");
    printMaze(start_x,start_y,end_x,end_y);
    
    if (solveMaze(start_x,start_y,end_x,end_y)) {
        printf("Solution path:\n");

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == start_x && j == start_y)
                    printf("S "); // Starting point
                else if (i == end_x && j == end_y)
                    printf("E "); // Ending point
                else if (solution[i][j] == 1)
                    printf("* "); // Solution path
                else if (maze[i][j] == 1)
                    printf("# "); // Wall
                else
                    printf("  "); // Path
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}


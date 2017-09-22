/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // Te gówna tutaj są OK
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(100000);
            
        }

        // sleep thread for animation's sake
        usleep(100000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    int dd = d * d;
    int numerki[dd];
    
    // Przyporządkowanie numerków do zbioru
    for (int i = 0; i < dd; i ++) {
        numerki[i] = dd - 1 - i;
    }
    // Na wypadek nieparzystości
    if (dd%2 == 0) {
        // Tutaj podmień 1 i 2
        numerki[dd-2] = 2;
        numerki[dd-3] = 1;
        // printf("Plansza parzysta, podmieniam!! \n");
        // usleep(200000);
    }
    // Tu był tester numerków
    /* for (int i = 0; i < dd; i ++) {
        printf("Numer po kolei: %i \n", numerki[i]);
        usleep(1000000);
    } */
 
    // Przenieś numerki na matrycę
    int x = 0;
    int y = 0;
    for (int i = 0; i < dd; i++) {
        board[x][y] = numerki[i];
        // printf("Board[%i][%i] = %i\n", x, y, numerki[i]);
        // usleep(1500000);        
        x = x + 1;
        if (x == d) {
            x = 0;
            y = y + 1;
        }
    }
 
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int x = 0;
    int y = 0;
    printf("\n");
    for (int i = 0; i < d*d; i++) {
        if (board[x][y] < 10 && board[x][y] > 0) {
            printf(" %i", board[x][y]);
        } else if (board[x][y] == 0) {
            printf(" _");
        } else {
            printf("%i", board[x][y]);
        }
        printf("  ");
        x = x + 1;
        if (x == d) {
            printf("\n\n");
            x = 0;
            y = y + 1;
        }
    }
    
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    // Good move = return true;
    // Sprawdzamy, czy w ramach numerków - tak
    if (tile < d*d) {
        
        // Sprawdźmy, gdzie jest zero
        int x0 = 0;
        int y0 = 0;
        for (int i = 0; i < d*d; i ++) {
            if (board[x0][y0] == 0) {
                // printf("Zero ma współrzędne %i %i\n", x0, y0);
                // usleep(1000000);
                break;
            } else {
                x0 = x0 + 1;
                if (x0 == d) {
                    x0 = 0;
                    y0 = y0 + 1;
                }
            }
        }        
        
        // Sprawdźmy, gdzie jest tile
        int x = 0;
        int y = 0;
        for (int i = 0; i < d*d; i ++) {
            if (board[x][y] == tile) {
                // printf("Pole ma współrzędne %i %i\n", x, y);
                // usleep(1000000);
                break;
            } else {
                x = x + 1;
                if (x == d) {
                    x = 0;
                    y = y + 1;
                }
            }
        }
        
        // Tester 
        // printf("Zero ma współrzędne %i %i\n", x0, y0);
        // printf("Pole ma współrzędne %i %i\n", x, y);
        // usleep(1000000);                
                
        // Teraz sprawdźmy, czy tile i zero są obok siebie
        if (((x == x0+1 || x == x0-1) && y == y0) || ((y == y0+1 || y == y0-1) && x == x0)) {
            // printf("To pole jest poprawne, jedźmy dalej.\n");
            // usleep(1000000);
            board[x][y] = 0;
            board[x0][y0] = tile;
            
            // To na samym końcu, po ruchu
            return true;
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int x = 0;
    int y = 0;
    int kolejnosc[d*d];
    
    // Wypełnij array kolejności!
    for (int i = 0; i < d*d; i++){
        kolejnosc[i] = board[x][y];
        x = x + 1;
        if (x == d) {
            x = 0;
            y = y + 1;
            if (y == d) {
                break;
            }
        }
    }
    
    // Sprawdźmy, czy indeks pokrywa się z cyferką (bez 2 ostatnich!)
    int wynik = 0;
    for (int i = 1; i < d*d; i++){
        if (i == kolejnosc[i-1]) {
            wynik = wynik + 1;
        }
    }
    // Wynik bez jednego oczka
    if (wynik == d*d - 1) {
        return true;
    }
    
    // Sprawdź czy elementy w array są kolejne
    
    
    // TODO
    return false;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(100000);
}
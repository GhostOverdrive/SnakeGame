#include <iostream>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>


using namespace std;


HANDLE hConsole;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void GotoXY(int X, int Y)
{
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

enum ConsoleColor
{
        Black         = 0,
        Blue          = 1,
        Green         = 2,
        Cyan          = 3,
        Red           = 4,
        Magenta       = 5,
        Brown         = 6,
        LightGray     = 7,
        DarkGray      = 8,
        LightBlue     = 9,
        LightGreen    = 10,
        LightCyan     = 11,
        LightRed      = 12,
        LightMagenta  = 13,
        Yellow        = 14,
        White         = 15
};

void SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


class Snake  //struct snake
{
    public:COORD *t; //dots
    public:int PCount; //count of Apples
};
enum uprawlenie{LEFT,UP,RIGHT,DOWN}; //direction of snake
class Game //BIG DATA
{
    public:Snake python; //Snake
    public:COORD Apple; //Apple
    public:int dx,dy; //moving
    public:int pause; //delay
    public:int dir; //direction

};


void PlusApple(Game &g) //func of placing Apples
{
    int i,x,y;
    int n = g.python.PCount;
    do
    {
        x = rand() % 56+3; //coordinate of Apple
        y = rand() % 19+3; //coordinate of Apple
        for(i = 0; i < n; i++)
        {
            if(x == g.python.t[i].X && y == g.python.t[i].Y) //checking that Apple-product is already in Python
                break;
        }
    }
    while(i < n);
    g.Apple.X = x; //remember the position of the Apple
    g.Apple.Y = y; //remember the position of the Apple
    SetConsoleCursorPosition(hConsole, g.Apple); //move the cursor to this position
    SetConsoleTextAttribute(hConsole,0x0c); //Apple factory color
    printf("%c", 36); //drawing the Apple

}


void SpeedGame(Game &g) //func of start of snake
{
    system("cls");
    g.python.PCount = 3; //how many points in the snake
    g.python.t = new COORD [3];//created the dots
    for(int i = 0; i < 3; i++)
    {
        g.python.t[i].X = 20 + i;
        g.python.t[i].Y = 20;

    }
    g.dx = 1;
    g.dy = 0;
    g.pause = 100;//speed of snake
    PlusApple(g);//draw an Apple
}
void Level()
{
    GotoXY(10,10);cout <<"You will never win!"<<endl;
    GotoXY(10,11);cout <<"If you're not careful!"<<endl;
}
void SnakeBeginning()
{
    GotoXY(10,15);cout <<"Collect 50 apples and then we'll see ;)"<<endl;
}
void WALL_2() //information shown on the wall
{
    SetColor(LightGreen, Black); GotoXY(14,0); cout << "Snake game by rock8forever(in Github)" << endl;
    GotoXY(64,2); cout << "Apples:0" << endl;
    GotoXY(64,3); cout <<  "Length:3"<< endl;
    GotoXY(64,4); cout <<  "Speed:0" << endl;
    GotoXY(64,6); cout << "Controls:" <<  endl;
    GotoXY(64,8); cout << "Esc:Exit" <<  endl;
    GotoXY(64,9); cout << "P:Pause" <<  endl;
    GotoXY(64,10); cout <<"S:Start" <<  endl;
    GotoXY(64,11); cout <<"L:Level" <<  endl;
    GotoXY(64,13); printf("%c%c",47,92); cout << ":Up" << endl;
    GotoXY(64,14); printf("%c%c",92,47); cout << ":Down" << endl;
    GotoXY(64,15); printf("%c",60); cout << "Left" << endl;
    GotoXY(64,16); printf("%c",62); cout << ":Right" << endl;
                {SetColor(LightMagenta, Black);

                GotoXY(2,2); //drawing top vertical wall-line
                int m = 0;
                for(m = 0; m < 60; m++)
                {
                    printf("*");
                }
                }

                {
                    GotoXY(2,24); //drawing bottom vertical wall-line
                    int m = 0;
                    for (m = 0; m < 60;m++)
                    {
                        printf("*");
                    }
                }
                {   //drawing left vertical wall-line
                    GotoXY(2,3); cout << "*" <<endl;
                    GotoXY(2,4); cout << "*" <<endl;
                    GotoXY(2,5); cout << "*" <<endl;
                    GotoXY(2,6); cout << "*" <<endl;
                    GotoXY(2,7); cout << "*" <<endl;
                    GotoXY(2,8); cout << "*" <<endl;
                    GotoXY(2,9); cout << "*" <<endl;
                    GotoXY(2,10); cout << "*" <<endl;
                    GotoXY(2,11); cout << "*" <<endl;
                    GotoXY(2,12); cout << "*" <<endl;
                    GotoXY(2,13); cout << "*" <<endl;
                    GotoXY(2,14); cout << "*" <<endl;
                    GotoXY(2,15); cout << "*" <<endl;
                    GotoXY(2,16); cout << "*" <<endl;
                    GotoXY(2,17); cout << "*" <<endl;
                    GotoXY(2,18); cout << "*" <<endl;
                    GotoXY(2,19); cout << "*" <<endl;
                    GotoXY(2,20); cout << "*" <<endl;
                    GotoXY(2,21); cout << "*" <<endl;
                    GotoXY(2,22); cout << "*" <<endl;
                    GotoXY(2,23); cout << "*" <<endl;
                }
                {   //drawing right vertical wall-line
                    GotoXY(61,3); cout << "*" <<endl;
                    GotoXY(61,4); cout << "*" <<endl;
                    GotoXY(61,5); cout << "*" <<endl;
                    GotoXY(61,6); cout << "*" <<endl;
                    GotoXY(61,7); cout << "*" <<endl;
                    GotoXY(61,8); cout << "*" <<endl;
                    GotoXY(61,9); cout << "*" <<endl;
                    GotoXY(61,10); cout << "*" <<endl;
                    GotoXY(61,11); cout << "*" <<endl;
                    GotoXY(61,12); cout << "*" <<endl;
                    GotoXY(61,13); cout << "*" <<endl;
                    GotoXY(61,14); cout << "*" <<endl;
                    GotoXY(61,15); cout << "*" <<endl;
                    GotoXY(61,16); cout << "*" <<endl;
                    GotoXY(61,17); cout << "*" <<endl;
                    GotoXY(61,18); cout << "*" <<endl;
                    GotoXY(61,19); cout << "*" <<endl;
                    GotoXY(61,20); cout << "*" <<endl;
                    GotoXY(61,21); cout << "*" <<endl;
                    GotoXY(61,22); cout << "*" <<endl;
                    GotoXY(61,23); cout << "*" <<endl;
                }
}


//moving and drawing
enum {ending, WALL,  PLUS, MOVE};
int Move(Game &g)
{
    int & n = g.python.PCount;
    COORD head = g.python.t[n - 1]; //head
    COORD tail = g.python.t[0]; //tail
    COORD next;
    next.X = head.X + g.dx;
    next.Y = head.Y + g.dy; //checking

    if(next.X < 3 || next.Y < 3 || next.X > 60 || next.Y > 23)//A wall?
        return WALL;

    if(n > 4)
    {
        for (int i = 0; i < n; i++)
            if (next.X == g.python.t[i].X && next.Y == g.python.t[i].Y) //Ran over yourself?
                return ending;
    }

    if (next.X == g.Apple.X && next.Y == g.Apple.Y)
    {
        COORD*temp = new COORD[++n]; //new array longer on 1
        for(int i = 0; i < n; i++)
            temp[i] = g.python.t[i]; //recopy
        temp[n - 1] = next; //add one
        delete [] g.python.t;
        g.python.t = temp;

        SetConsoleCursorPosition(hConsole,head);
        SetConsoleTextAttribute(hConsole, 0x0a); //paint over the Apple that was eaten
        printf("*");
        SetConsoleCursorPosition(hConsole,next);
        SetConsoleTextAttribute(hConsole,0x0a);
        printf("%c",1);
        PlusApple(g);
        return PLUS;
    }

    for (int i = 0; i < n - 1; i++)
        g.python.t[i] = g.python.t[i + 1];
    g.python.t[n - 1] = next;
    SetConsoleCursorPosition(hConsole,tail);//paint the tail
    printf(" ");

    SetConsoleCursorPosition(hConsole,head);
    SetConsoleTextAttribute(hConsole, 0x0a);//paint the tail in green
    printf("*");
    SetConsoleCursorPosition(hConsole,next);
    SetConsoleTextAttribute(hConsole,0x0f); //paint head in white
    printf("%c",38);

    return MOVE;
}

void intro()
{
    GotoXY(15,10);
    printf("Hello! Welcome to my version of 'SNAKE'");
    GotoXY(15,11);
    printf("Simple use arrows to move your character )");
    GotoXY(18,15);
    printf("Enjoy the game and good luck!");
    getch();
}

int main()
{

    setlocale(LC_ALL,"Russian");
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    intro();
    int key = 0, count = 0;
    bool Pause = false;
    Game g;
    SpeedGame(g);
    WALL_2();
    srand(time(0));
    bool pause = false;
    while (key != 27)
    {
        while (!kbhit()) //waiting for the command
        {
            if (Pause)
            {
                Sleep(1);
                continue;
            }

            switch(Move(g))//moving
            {

            case PLUS:
                ++count;
                g.pause--;
                SetColor(LightGreen, Black);
                GotoXY(64,2); cout << "Apples: " << count << endl;
                GotoXY(64,3); cout << "Length: " << g.python.PCount << endl;
                GotoXY(64,4); cout << "Speed: " << g.pause << endl;
                GotoXY(64,6); cout << "Controls:" <<  endl;
                GotoXY(64,8); cout << "Esc:Exit" <<  endl;
                GotoXY(64,9); cout << "P:Pause" <<  endl;
                GotoXY(64,10); cout <<"S:Start" <<  endl;
                GotoXY(64,11); cout <<"L:Level" <<  endl;
                GotoXY(64,13); printf("%c%c",47,92); cout << ":Up" << endl;
                GotoXY(64,14); printf("%c%c",92,47); cout << ":Down" << endl;
                GotoXY(64,15); printf("%c",60); cout << "Left" << endl;
                GotoXY(64,16); printf("%c",62); cout << ":Right" << endl;
                if (count == 50)
                {
                    SetColor(Red, Black);
                    GotoXY(23,12);
                    cout << "***YOU  WON!!!***" << endl;
                    getch();
                    return(0);
                }
                break;

            case WALL:

            case ending:
                SetColor(Red, Black);
                GotoXY(23,12);
                printf("G A M E   O V E R");
                Sleep(3000);
                return 0;
                //getch();
                break;
            }

            Sleep(g.pause); //delay
        }
    key = getch();

        if (key == 'P' || key == 'p')
            Pause = !Pause;
            else if (key == 'S' || key == 's')
            SnakeBeginning();
        else if(key == 'L' || key == 'l')
            Level();
        else if (key == 0 || key == 224)
        {
            key = getch();

            if (key == 72 && g.dir != DOWN)
            {
                g.dir = UP;
                g.dx = 0;
                g.dy = -1;
            }
            else if (key == 80 && g.dir != UP)
            {
                g.dir = DOWN;
                g.dx = 0;
                g.dy = 1;
            }
            else if (key == 75 && g.dir != RIGHT)
            {
                g.dir = LEFT;
                g.dx = -1;
                g.dy = 0;
            }
            else if (key == 77 && g.dir != LEFT)
            {
                g.dir = RIGHT;
                g.dx = 1;
                g.dy = 0;
            }
        }
    }
}

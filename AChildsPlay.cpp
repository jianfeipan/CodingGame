#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 /*
 0 up
 1 right
 2 down
 3 left
 */
bool canGo(int direction, int x, int y, string * maze, int width, int height)
{
    switch(direction)
    {
        case 0://N
        {
            return y>0 && maze[y-1][x] != '#';
        }
        case 1://E
        {
            return x<width-1 && maze[y][x+1] != '#';
        }
        case 2://S
        {
            return y<height-1 && maze[y+1][x] != '#';
        }
        case 3://W
        {
            return x > 0 && maze[y][x-1] != '#';
        }
    }
}

void move(int direction, int & x, int & y, string * maze, int width, int height)
{
    switch(direction)
    {
        case 0://N
        {
            y--;
            return;
        }
        case 1://E
        {
            x++;
            return;
        }
        case 2://S
        {
            y++;
            return;
        }
        case 3://W
        {
            x--;
            return;
        }
    }
}


int main()
{
    int w;
    int h;
    cin >> w >> h; cin.ignore();
    long long n;
    cin >> n; cin.ignore();
    
    string maze[h];
    int startX = 0;
    int startY = 0;
    int dir = 0;
    for (int i = 0; i < h; i++) {
        getline(cin, maze[i]);
    }
    
    for(int y = 0; y < h; y++)
    {
        const auto & x = maze[y].find('O');
        if(x != string::npos)
        {
            startX = x;
            startY = y;
            break;
        }
    }
    
    int x = startX;
    int y = startY;
    int steps = 0;
    while(steps < n)
    {
        /*
        up : y --
        right : x++
        down : y++
        left : x--
        */
        if(!canGo(dir, x,y, maze, w, h))
        {
            /*turns right*/
            dir = (dir +1 )%4;
            
        }
        move(dir, x, y, maze, w, h);
        steps++;
        
        if(x == startX && y == startY)
        {
            n = n%steps;
            steps = 0;
        }
    }
    
    cout<< x << " "<< y<< endl;
    
}

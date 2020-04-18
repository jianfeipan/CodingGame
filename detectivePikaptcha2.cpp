#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 //direction
 /*
 N = 0
 E = 1, 
 S = 2,
 W = 3
 
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

bool move(int direction, int & x, int & y, string * maze, int width, int height)
{
    switch(direction)
    {
        case 0://N
        {
            y--;
            break;
        }
        case 1://E
        {
            x++;
            break;
        }
        case 2://S
        {
            y++;
            break;
        }
        case 3://W
        {
            x--;
            break;
        }
    }                
}

char DIRECTION[4] = {'^','>','v','<'};

std::pair<int, int> findStartPos(string * maze, int height, int & dir)
{
    for(int y = 0; y<height ; y++ )
    {
        for(int direction = 0; direction < 4; direction++)
        {
            size_t x = maze[y].find(DIRECTION[direction]);
            if(x!=string::npos)
            {
                dir = direction;
                return std::pair<int, int>(x, y);
            }
        }
    }
    return std::pair<int, int>();
}

int main()
{
    int width;
    int height;
    cin >> width >> height; cin.ignore();
    
    string maze[height];
    
    
    for (int i = 0; i < height; i++) {
        cin >> maze[i]; cin.ignore();
    }
    
    string side;
    cin >> side; cin.ignore();
    bool left = side == "L";
    int dir = 0;
    
    const auto & start = findStartPos(maze, height, dir);
    int startX = start.first;
    int startY = start.second;
    
    maze[startY][startX] = '0';
    int x = startX;
    int y = startY;
    int count = 0;
    while(maze[startY][startX]!='1')
    {
        if(canGo((dir + (left?3:1))%4, x, y, maze, width, height))
        {
            dir= (dir + (left?3:1))%4; 
            move(dir, x,y, maze, width, height);
            maze[y][x]++;
        }
        else if(canGo(dir, x, y, maze, width, height))
        {
            move(dir, x,y, maze, width, height);
            maze[y][x]++;
        }
        else if(canGo((dir + (left?1:3))%4, x, y, maze, width, height))
        {
            dir= (dir + (left?1:3))%4; 
            move(dir, x,y, maze, width, height);
            maze[y][x]++;
        }else if(canGo((dir + 2)%4, x, y, maze, width, height))
        {
            dir= (dir + 2)%4;
            move(dir, x,y, maze, width, height);
            maze[y][x]++;
        }
        else
        {
            break;
        }
    }
    
    for (int i = 0; i < height; i++) {

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << maze[i] << endl;
    }
}

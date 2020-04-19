#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
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


int main()
{
    int width;
    int height;
    cin >> width >> height; cin.ignore();
    
    string maze[height];
    
    for (int i = 0; i < height; i++) {
        cin >> maze[i]; cin.ignore();
    }
    
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++)
        {
            if(maze[i][j] != '#')
            {
                for(int dir = 0; dir < 4 ; dir ++)
                {
                    if(canGo(dir, j, i, maze, width, height))
                    {
                        maze[i][j]++;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < height; i++) {

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << maze[i] << endl;
    }
}

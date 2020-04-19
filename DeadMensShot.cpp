#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
bool withIn(int x,int y,int ax,int ay,int bx,int by)
{
    if(x==0 && y == 0)
        return true;
    if(x*(by - ay) != y*(bx-ax))
    {
        return std::pow((y*(bx-ax) -x * (by - ay)), 2) <= std::pow(ay*bx - ax*by,2);
    }
    else
    {
        cerr<< x << "?" <<y<<endl;
        cerr<< x << "?" <<y<<endl;
        return (std::abs(x-ax) + std::abs(x-bx) == std::abs(ax-bx))
        && (std::abs(y-ay) + std::abs(y-by) == std::abs(ay-by)) ;
    }
}
  

bool between(int x,int y,int ax,int ay,int bx,int by)
{
    /*

    degree(ax, ay) < degree(x,y) < degree(bx,by) 

    */
    
    if(ax*y >= ay * x)
    {
        return bx*y <= by*x;
    }
    return false;
}
 
bool hit(int x, int y, std::vector<std::pair<int, int> > & target )
{
    for(int i = 0; i < target.size(); i++)
    {
        const auto & pointA = target[i];
        const auto & pointB = target[(i+1)% target.size()];    
        
        if(between(x,y,pointA.first,pointA.second,pointB.first,pointB.second))
        {
            return withIn(x,y,pointA.first,pointA.second,pointB.first,pointB.second);
        }
        
    }
}

int main()
{
    int N;
    cin >> N; cin.ignore();
    
    std::vector<std::pair<int, int> > target;
    
    for (int i = 0; i < N; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        target.push_back({x, y});
        cerr<< x<< ' ' << y<< endl;
    }
    

    
    
    int M;
    cin >> M; cin.ignore();
    
    for (int i = 0; i < M; i++) {
        int x;
        int y;
        cin >> x >> y; cin.ignore();
        //cerr<< x<< '-' << y<< endl;
        cout <<( hit(x, y, target) ? 
        "hit":"miss" )<< endl;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

}

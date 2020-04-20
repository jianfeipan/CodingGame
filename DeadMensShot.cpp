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
 

bool hit(int x, int y, std::vector<std::pair<int, int> > & target )
{
    int crossCount = 0;
    for(int i = 0; i < target.size(); i++)
    {
        const auto & pointA = target[i];
        const auto & pointB = target[(i+1)% target.size()];    
        
        const auto & ax = pointA.first;
        const auto & ay = pointA.second;
        const auto & bx = pointB.first;
        const auto & by = pointB.second;
        
        if((ay != by)
        && std::max(ay, by) > y
        && std::min(ay, by) <= y)
        {
            /*
            (x-ax) / (y - ay) = (bx - ax) / (by - ay)   
            */
            if( x < (bx - ax)* (y - ay) / (by - ay)  + ax)
            {
                crossCount++;
                //cerr<< x<< '-' << y<< ':' << crossCount<< ax << ','<<ay<< " to " <<bx<<','<<by << " :: " << x<< "<= "<<((bx - ax)* (y - ay) / (by - ay)  + ax) <<endl;
            }
            
        }
        
    }
    return crossCount%2 == 1;
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

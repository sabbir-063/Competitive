#include <iostream>
using namespace std;

char getNahidMove(char robot1, char robot2)
{
    if ((robot1 == 'R' && robot2 == 'S') || (robot1 == 'S' && robot2 == 'R')){
        return 'R';
    }
    else if ((robot1 == 'S' && robot2 == 'P') || (robot1 == 'P' && robot2 == 'S')){
        return 'S';
    }
    else if ((robot1 == 'R' && robot2 == 'P') || (robot1 == 'P' && robot2 == 'R')){
        return 'P';
    }
    else if(robot1 == robot2){
        if(robot1 == 'R'){
            return 'P';
        }
        else if(robot1 == 'P'){
            return 'S';
        }
        else{
            return 'R';
        }
    }
}

int main()
{
    int n;
    cin >> n;

    string robot1Moves, robot2Moves;
    cin >> robot1Moves >> robot2Moves;

    for (int i = 0; i < n; i++)
    {
        char nahidMove = getNahidMove(robot1Moves[i], robot2Moves[i]);
        cout << nahidMove;
    }

    cout << endl;

    return 0;
}

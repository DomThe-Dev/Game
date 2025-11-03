/*  GAME
* - If including a library in a file, use <>, rather than "". "" only for own headers
*/

#include "managers/GameManager.h"
#include "utils/Common.h"

/// <summary>
/// Entry point of program. Keep it as simple as physically possible. Good in case I need to run tests, lets me isolate
/// this stuff.
/// </summary>
/// <returns>0 for success, 1 for error</returns>
int main() 
{
    try
    {
        GameManager game;
        game.Start();
    }
    catch (const std::exception& e) {
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
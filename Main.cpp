/**
 * Tests for messageboard-a.
 *
 * AUTHOR: Yuval Moshe
 * 
 * Date: 2021-03
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

int main()
{
    Board board;
    board.post(0, 3, Direction::Horizontal, "My");
    board.post(0, 0, Direction::Horizontal, "Hey");
    board.post(0, 5, Direction::Horizontal, "Name");
    board.post(0, 9, Direction::Horizontal, "Is");
    board.post(0, 11, Direction::Horizontal, "Yuval");
    board.post(1, 0, Direction::Horizontal, "Hello Hello");
    board.post(2, 0, Direction::Horizontal, "bbbb");
    board.post(3, 0, Direction::Horizontal, "ttttt");
    board.post(0, 0, Direction::Vertical, "Hellow EveryBody");


    cout << board.read(0, 0, Direction::Vertical, 20);
    return 0;
}
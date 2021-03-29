#pragma once
#include <map>
#include <iterator>
using namespace std;
#include "Direction.hpp"
using namespace ariel;

namespace ariel
{
    class Board
    {
        // map<int, Node*> Cols;
        // map<int, Node*> Rows;
        map<int, map<int, char> *> board;

    public:
        void post(unsigned int row, unsigned int column, Direction dir, const string message);
        string read(unsigned int row, unsigned int column, Direction dir, unsigned int length);
        void show();
        ~Board()
        {
            for (map<int, map<int, char>*>::iterator it = board.begin(); it!=board.end(); it++){
                delete it->second;
            }
        }

    private:
        void post_vert(int row, int column, const string message);
        void post_horz(int row, int column, const string message);
        string read_horz(int row, int column, int length);
        string read_vert(int row, int column, int length);
    };

}
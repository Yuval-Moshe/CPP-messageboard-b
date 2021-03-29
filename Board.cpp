#include <iostream>
#include <array>
using namespace std;
#include "Direction.hpp"
#include "Board.hpp"
using namespace ariel;

namespace ariel
{
    void Board::post(unsigned int row, unsigned int column, Direction dir, const string message)
    {
        if (dir == Direction::Horizontal)
        {
            post_horz((const int) row, (const int) column, message);
        }
        else
        {
            post_vert((const int) row, (const int) column, message);
        }
    }
    string Board::read(unsigned int row, unsigned int column, Direction dir, unsigned int length)
    {
        if (dir == Direction::Horizontal)
        {
            return read_horz((const int) row, (const int) column, (const int) length);
        }
        return read_vert((const int) row, (const int) column, (const int) length);
    }
    void Board::show() {}

    string Board::read_horz(const int row,  const int column,  const int length)
    {
        string ans = "";
        if (board.find(row) == board.end())
        {
            for (int i = 0; i < length; i++)
            {
                ans += "_";
            }
            return ans;
        }
        map<int, char> *row_map = board.find(row)->second;
        for (int i = 0; i < length; i++)
        {
            // cout << "Row is " << row << ", Col is " << column + i << endl;
            if (row_map->find(column + i) == row_map->end())
            {
                ans += "_";
            }
            else
            {
                ans += row_map->find(column + i)->second;
            }
        }
        return ans;
    }
    string Board::read_vert(const int row, const int column, const int length)
    {
        string ans = "";
        for (int i = 0; i < length; i++)
        {
            if (board.find(row + i) == board.end())
            {
                ans += "_";
            }
            else
            {
                map<int, char> *row_map = board.find(row + i)->second;
                if (row_map->find(column) == row_map->end())
                {
                    ans += "_";
                }
                else
                {
                    ans += row_map->find(column)->second;
                }
            }
        }
        return ans;
    }

    void Board::post_horz(const int row, const int column, const string message)
    {
        if (board.find(row) == board.end())
        {
            map<int, char> *row_map = new map<int, char>;
            board.insert({row, row_map});
        }
        int len = message.length();
        unsigned long col_l = (unsigned long)column;
        map<int, char> *row_map = board.find(row)->second;
        for (unsigned long i = 0; i < len; i++)
        {
            char curr = message[i];
            if (row_map->find(col_l + i) == row_map->end())
            {
                row_map->insert({col_l + i, curr});
                cout << row_map->find(col_l + i)->second << endl;
            }
            else
            {
                row_map->find(col_l + i)->second = curr;
                cout << row_map->find(col_l + i)->second << endl;
            }
        }
    }
    void Board::post_vert(const int row, const int column, const string message)
    {

        int len = message.length();
        map<int, char> *row_map = board.find(row)->second;
        unsigned long row_l = (unsigned long)row;
        for (unsigned long i = 0; i < len; i++)
        {
            if (board.find(row_l + i) == board.end())
            {
                map<int, char> *row_map = new map<int, char>;
                board.insert({row_l + i, row_map});
            }
            map<int, char> *row_map = board.find(row_l + i)->second;
            char curr = message[i];
            if (row_map->find(column) == row_map->end())
            {
                row_map->insert({column, curr});
                cout << row_map->find(column)->second << endl;
            }
            else
            {
                row_map->find(column)->second = curr;
                cout << row_map->find(column)->second << endl;
            }
        }
    }

}

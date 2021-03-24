#pragma once

#include "Board.hpp"
using namespace std;

namespace ariel {

    void Board::post(unsigned int row, unsigned int column, Direction direction, string message) {}
	
	void Board::show() {}
    
	string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int numToRead) {
        return "_";
    }

}
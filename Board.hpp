#pragma once

#include "Direction.hpp"
#include <string>
using namespace std;

namespace ariel {
    class Board {
		public:
			static void post( unsigned int row,  unsigned int column, Direction direction, string message);
			static string read( unsigned int row,  unsigned int column, Direction direction,  unsigned int numToRead);
			void show();
    };
}
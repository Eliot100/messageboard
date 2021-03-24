#include "doctest.h"
#include "Board.hpp"
#include <string>

using namespace ariel;
using namespace std;


TEST_CASE("Tests") {
    Board board;
	
    CHECK(board.read(0,0,Direction::Horizontal,10).compare("__________"));
    CHECK(board.read(0,0,Direction::Vertical,10).compare("__________"));
	
	CHECK_NOTHROW(board.post(9,9,Direction::Horizontal,"qwe"));
    CHECK(board.read(9,9,Direction::Horizontal,1).compare("q"));
    CHECK(board.read(10,9,Direction::Horizontal,1).compare("w"));
    CHECK(board.read(11,9,Direction::Horizontal,1).compare("e"));
    CHECK(board.read(9,9,Direction::Horizontal,3).compare("qwe"));
    CHECK(board.read(8,9,Direction::Horizontal,5).compare("_qwe_"));
    CHECK(!board.read(9,9,Direction::Horizontal,3).compare("___"));
	
	CHECK_NOTHROW(board.post(9,9,Direction::Vertical,"lkj"));
    CHECK(!board.read(9,9,Direction::Horizontal,1).compare("q"));
    CHECK(board.read(9,9,Direction::Horizontal,1).compare("l"));
    CHECK(board.read(10,9,Direction::Horizontal,1).compare("k"));
    CHECK(board.read(11,9,Direction::Horizontal,1).compare("j"));
    CHECK(board.read(9,9,Direction::Vertical,3).compare("lkj"));
    CHECK(board.read(8,9,Direction::Horizontal,5).compare("_lkj_"));
    CHECK(!board.read(9,9,Direction::Horizontal,3).compare("___"));
	
	CHECK_NOTHROW(board.post(0,10000,Direction::Horizontal,"if"));
    CHECK(board.read(0,10000,Direction::Horizontal,1).compare("i"));
    CHECK(board.read(0,10001,Direction::Horizontal,1).compare("f"));
    CHECK(board.read(0,10000,Direction::Vertical,2).compare("if"));
    CHECK(board.read(0,10000,Direction::Vertical,3).compare("if_"));
	
	CHECK_NOTHROW(board.post(10000,0,Direction::Vertical,"else"));
    CHECK(board.read(10000,0,Direction::Horizontal,1).compare("e"));
    CHECK(board.read(10001,0,Direction::Horizontal,1).compare("l"));
    CHECK(board.read(10002,0,Direction::Horizontal,1).compare("s"));
    CHECK(board.read(10003,0,Direction::Horizontal,1).compare("e"));
    CHECK(board.read(10000,0,Direction::Vertical,2).compare("el"));
    CHECK(board.read(10000,0,Direction::Vertical,3).compare("els"));
    CHECK(board.read(10000,0,Direction::Vertical,4).compare("else"));
    CHECK(!board.read(9,9,Direction::Horizontal,3).compare("___"));
	
    CHECK_THROWS(board.post(0,-5,Direction::Horizontal,"ghs"));
    CHECK_THROWS(board.post(-1,3,Direction::Horizontal,"5sdff"));
    CHECK_THROWS(board.post(-7,-2,Direction::Horizontal,"rts"));
    CHECK_THROWS(board.post(7,-1,Direction::Vertical,"ujs"));
    CHECK_THROWS(board.post(-3,2,Direction::Vertical,"unej"));
    CHECK_THROWS(board.post(-6,-6,Direction::Vertical,"ehric"));
	
	CHECK_THROWS(board.read(-1,0,Direction::Horizontal,2));
    CHECK_THROWS(board.read(2,-5,Direction::Horizontal,3));
    CHECK_THROWS(board.read(-2,-6,Direction::Horizontal,4));
	CHECK_THROWS(board.read(-5,7,Direction::Vertical,1));
    CHECK_THROWS(board.read(4,-2,Direction::Vertical,3));
    CHECK_THROWS(board.read(-4,-3,Direction::Vertical,5));
	
	CHECK_NOTHROW(board.show());
}
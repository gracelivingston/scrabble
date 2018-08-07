#include "Board.hxx"

#include <vector>

using std::vector;

vector<Board::coordinate> word_3 = {
    pair('a', 1),
    pair('h', 1),
    pair('a', 8),
    pair('o', 8),
    pair('a', 15),
    pair('h', 15),
    pair('o', 15)
};

vector<Board::coordinate> word_2 = {
    pair('b', 2),
    pair('n', 2),
    pair('c', 3),
    pair('m', 3),
    pair('d', 4),
    pair('l', 4),
    pair('e', 5),
    pair('k', 5),

    pair('k', 11),
    pair('e', 11),
    pair('l', 12),
    pair('d', 12),
    pair('m', 13),
    pair('c', 13),
    pair('n', 14),
    pair('b', 14)
};

vector<Board::coordinate> letter_3 = {

}
Board::Board() : _board() {
    // The 3-point tiles
    _board[pair('a', 1)] = 3;
}

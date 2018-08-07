/**
 * \file Board.hxx
 *
 * \brief The actual Scrabble board.
 */

#ifdef BOARD_HXX
#define BOARD_HXX

#include <utility>
#include <map>

using std::pair;
using std::map;

/** The game board, including the multiplier for each square. */
class Board {
public:
    /** Create a new board. */
    Board();

    /** A board position. The column is a letter ‘A-O’ and the row is
     * a number 1-15. */
    typedef pair<unsigned char, unsigned int> coordinate;

    /** The multiplier for a given position. */
    unsigned multiplier(position p);
protected:
    typedef map<coordinate, unsigned integer> _Board;
    _Board _board;
};

#endif

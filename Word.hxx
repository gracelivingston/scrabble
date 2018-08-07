/**
 * \file Word.hxx
 *
 * \brief Represents the word data.
 */

#include <string>
#include <vector>
#include <istream>
#include <ostream>

using std::string;
using std::istream;
using std::ostream;
using std::vector;

/**
 * The letters of the alphabet and their frequencies.
 */
class Letters {
private:
    friend ostream &operator<<(ostream &, const Letters&);
    friend istream &operator>>(istream &, Letters&);
    friend class Words;
    unsigned int _n;      /**! The number of letters, including
                               wildcards. */
    unsigned int _cs[27]; /**! A counter for each letter (1-26) and
                           for wildcard tiles (0). */

    string _w;      /**! The actual word itself. */

public:
    Letters(); /**! An empty constructor for operator>>. */

    /** Create a frequency list for a string. */
    Letters(const string &word);

    Letters(const Letters &ls);

    /**
     * True if this fully contains the letters in ls.
     *
     * This compares the non-0 letters of this to ls. It will use each
     * blank tile in this at most once each.
     */
    bool operator>=(const Letters &ls) const;

    /**
     * Copy assignment operator.
     */
    Letters &operator=(const Letters &ls);

    /**
     * The base score of this letter combination.
     */
    const unsigned int score() const;

    /**
     * The underlying Word.
     */
    const string &word() const;
};

/**
 * Iterates through a word list on disk one-way and returns the
 * longest words containing the letters of the search string.
 */
class Words {
private:
    const string &_wfn;
public:
    Words(const string &wfn);

    /**
     * Search the word list for all entries that are contained by ls.
     */
    vector<Letters> &operator()(const Letters &ls, vector<Letters> &wds);
};

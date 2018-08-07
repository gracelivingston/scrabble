/**
 * \file Word.cxx
 */

#include <fstream>
#include "Word.hxx"
#include <iostream>

using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;

vector<unsigned int> Scores = {
    0,
    1, 3, 3, 2, 1,
    4, 2, 4, 1, 8,
    5, 1, 3, 1, 1,
    3, 10, 1, 1, 1,
    1, 4, 4, 8, 4,
    10
};

Letters::Letters(const string &word) : _n(0), _w(word) {
    for(unsigned i = 0; i < 27; i++)
        _cs[i] = 0;

    // Increment the counter for each letter in the given search word.
    for(string::const_iterator c = word.begin(); c != word.end(); c++) {
        _n++;
        if (*c == '_')
            _cs[0]++;
        else
            _cs[(*c) & 31]++;
    }
}

Letters::Letters(const Letters &ls) : _n(ls._n), _w(ls._w) {
    for(unsigned i = 0; i < 27; i++) {
        _cs[i] = ls._cs[i];
    }
}

bool Letters::operator>=(const Letters &ls) const {
    if (_n < ls._n)
        // If we have fewer letters than ls we’re too small.
        return false;

    // Keep track of remaining blank letters.
    unsigned blanks(_cs[0]);
    for(unsigned i = 1; i < 27; i++) {
        // Do we have more of this letter than ls?
        if (_cs[i] >= ls._cs[i])
            continue;

        // If not, do we have enough blanks so far?
        if (blanks > 0) {
            blanks--;
            continue;
        }

        // If not, we’re too small.
        return false;
    }

    // Congratulations, we’re large enough.
    return true;
}

Letters::Letters() {}

const string &Letters::word() const{
    return _w;
}

Letters &Letters::operator=(const Letters &ls) {
    _n = ls._n;
    for (unsigned i = 0; i < 27; i++)
        _cs[i] = ls._cs[i];

    _w = ls._w;

    return *this;
}

const unsigned int Letters::score() const {
    unsigned int s(0);
    for (unsigned i = 0; i < 27; i++) {
        s += _cs[i] * Scores[i];
    }

    return s;
}
istream &operator>>(istream &is, Letters &ls) {
    string s;
    is >> s;
    ls = Letters(s);
    return is;
}

ostream &operator<<(ostream &os, const Letters &ls) {
    os << ls._w;
    return os;
    os << ls._w << "[" << ls.score() << "] (" << ls._n << ")" << endl;

    for(unsigned i = 0; i < 27; i++) {
        os << ls._cs[i];
    }

    os << endl;

    return os;
}

Words::Words(const string &wfn) : _wfn(wfn) {}

vector<Letters> &Words::operator()(const Letters &ls, vector<Letters> &wds) {
    ifstream wf("SOWPODS_complete.txt");

    string s;
    Letters w;
    wds.clear();
    wds.reserve(250000);
    while(!wf.eof() && !wf.bad()) {
        wf >> w;

        if (ls >= w) {
            wds.push_back(w);
        }
    }

    wf.close();
    return wds;
}

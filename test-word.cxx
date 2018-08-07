#include "Word.hxx"

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::max_element;

vector <string> a = {
    "DELIRYZ",
    "EDFGON_",
    "ABC_DEF",
    "QBMP_I_",
    "SSARLNE",
    "ZUQI_DE",
    "FRIENDS"
};

int main(int argc, char **argv) {
    cout << "Tests: " << a.size() << endl;

    Words ws("SOWPODS_complete.txt");

    vector<Letters> ls;

    for(vector<string>::iterator i = a.begin();
        i != a.end();
        i++) {
        Letters v(*i);

        ws(v, ls);
        cout << *i << ": " << ls.size() << endl;
        cout << "Largest Word: " << *max_element(
            ls.begin(), ls.end(),
            [](const Letters &a, const Letters &b)->bool {
                return a.score() < b.score();
            }) << endl;
        ls.clear();
    }

    return 0;
}

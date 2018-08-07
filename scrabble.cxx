#include "Word.hxx"

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#include <time.h>
#endif

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::ifstream;
using std::max_element;

double now() {
#ifdef _WIN32
    SYSTEMTIME t_s;
    GetSystemTime(&t_s);

    FILETIME t_f;
    SystemTimeToFileTime(&t_s, &t_f);

    ULARGE_INTEGER t_u;
    t_u.HighPart = t_f.dwHighDateTime;
    t_u.LowPart = t_f.dwLowDateTime;

    return double(t_u.QuadPart) / 10000000.0;
#else
    struct timeval t;

    gettimeofday(&t, NULL);

    return t.tv_sec + t.tv_usec / 1000000.
#endif
}

#define DICTIONARY "SOWPODS_complete.txt"

int main(int argc, char **argv) {
    Words ws(DICTIONARY);

    if (argc != 2) {
        cerr << "Usage: " << argv[0];
        cerr << " <tiles-file>" << endl;
        cerr << endl;
        return 1;
    }


    ifstream tls(argv[1]);
    vector<Letters> ls;

    Letters v;
    while(!tls.eof()) {
        double t0 = now();

        tls >> v;

        if (v.word().size() == 0)
            continue;
        cout << "RACK: " << v << endl;

        ws(v, ls);

        if (ls.empty()) {
            cout << "PASS" << endl;
            continue;
        }

        Letters x(*max_element(
            ls.begin(), ls.end(),
            [](const Letters &a, const Letters &b)->bool {
                return a.score() < b.score();
            }));

        unsigned s(7 - (x.word().size() / 2) + 1);
        cout << "PLACE WORD: " << x << "  ";
        cout << s << " " << x.score() << " " << endl;

        double tF = now();

        cout << "ELAPSED TIME: " << tF - t0 << "s" << endl;
    }

    return 0;
}

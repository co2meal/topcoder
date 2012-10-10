#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <ctime>

using namespace std;

class SilverDistance {
    public:
    int minSteps(int sx, int sy, int gx, int gy) {
        int dx, dy;
        dx = abs(gx-sx);
        dy = abs(gy-sy);
        // if(dy % 2) dy --; Wrong

        int res = 0;


        if ((dx+dy) % 2) {
            res ++;
            if (gy > sy) dy--;
            else dy++;
        }

        if (dx > dy) swap(dx, dy);

        return res +dy;


        return 0;
    }
};

// CUT begin

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }



bool do_test(int sx, int sy, int gx, int gy, int expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    SilverDistance instance;
    int result = instance.minSteps(sx, sy, gx, gy);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;

    if (result == expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(expected) << endl;
        cout << "           Received: " << pretty_print(result) << endl;
        return false;
    }
}

bool run_testcase(int no) {
    switch (no) {
        case 0: {
            int sx = 1;
            int sy = 0;
            int gx = 1;
            int gy = 9;
            int expected = 9;
            return do_test(sx, sy, gx, gy, expected, no);
        }
        case 1: {
            int sx = 0;
            int sy = 0;
            int gx = -4;
            int gy = 3;
            int expected = 5;
            return do_test(sx, sy, gx, gy, expected, no);
        }
        case 2: {
            int sx = 0;
            int sy = 0;
            int gx = 5;
            int gy = 8;
            int expected = 8;
            return do_test(sx, sy, gx, gy, expected, no);
        }
        case 3: {
            int sx = -487617;
            int sy = 826524;
            int gx = 892309;
            int gy = -918045;
            int expected = 1744571;
            return do_test(sx, sy, gx, gy, expected, no);
        }
        case 4: {
            int sx = -27857;
            int sy = 31475;
            int gx = -27857;
            int gy = 31475;
            int expected = 0;
            return do_test(sx, sy, gx, gy, expected, no);
        }

        // Your custom testcase goes here
        case 5:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "SilverDistance (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1349872113;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end

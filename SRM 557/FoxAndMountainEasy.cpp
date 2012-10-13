#include <cstdio>
#include <cmath>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
#include <sstream>
#include <cassert>
#include <map>
#include <stack>


#define FOR(I,A,B) for(int I=(A);I<(B);I++)
#define REP(I,N) FOR(I,0,N)
#define ALL(A) (A).begin(),(A).end()

#define SQR(x) ((x)*(x))
#define PB(x) push_back(x)

#define PI (acos(-1.0))

using namespace std;

typedef vector<int> VI;
typedef vector< vector<int> > VVI;

class FoxAndMountainEasy {
    public:
    string possible(int n, int h0, int hn, string history) {
        int prepend = 0;
        int delta = 0;
        REP (i, history.size()) {
            if (history[i] == 'U') delta ++;
            else delta --;
            prepend = min(prepend, h0 + delta);
        }

        prepend *= -1;

        int remainx = n - prepend - history.size();
        int remainy = hn - (h0 + prepend + delta);

        cout << remainx << " , " << remainy << endl;

        if (remainx < 0) return "NO";
        if (abs(remainx) < abs(remainy)) return "NO";
        if (remainx % 2 != abs(remainy) % 2) return "NO";
        return "YES";
    }
};

// CUT begin

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }



bool do_test(int n, int h0, int hn, string history, string expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    FoxAndMountainEasy instance;
    string result = instance.possible(n, h0, hn, history);
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
            int n = 4;
            int h0 = 0;
            int hn = 4;
            string history = "UU";
            string expected = "YES";
            return do_test(n, h0, hn, history, expected, no);
        }
        case 1: {
            int n = 4;
            int h0 = 0;
            int hn = 4;
            string history = "D";
            string expected = "NO";
            return do_test(n, h0, hn, history, expected, no);
        }
        case 2: {
            int n = 4;
            int h0 = 100000;
            int hn = 100000;
            string history = "DDU";
            string expected = "YES";
            return do_test(n, h0, hn, history, expected, no);
        }
        case 3: {
            int n = 4;
            int h0 = 0;
            int hn = 0;
            string history = "DDU";
            string expected = "NO";
            return do_test(n, h0, hn, history, expected, no);
        }
        case 4: {
            int n = 20;
            int h0 = 20;
            int hn = 20;
            string history = "UDUDUDUDUD";
            string expected = "YES";
            return do_test(n, h0, hn, history, expected, no);
        }
        case 5: {
            int n = 20;
            int h0 = 0;
            int hn = 0;
            string history = "UUUUUUUUUU";
            string expected = "YES";
            return do_test(n, h0, hn, history, expected, no);
        }
        case 6: {
            int n = 20;
            int h0 = 0;
            int hn = 0;
            string history = "UUUUUUUUUUU";
            string expected = "NO";
            return do_test(n, h0, hn, history, expected, no);
        }

        case 7: {
            int n = 25;
            int h0 = 190;
            int hn = 165;
            string history = "DUUUDUUUDDUUUUUDD";
            string expected = "NO";
            return do_test(n, h0, hn, history, expected, no);
        }

        // Your custom testcase goes here
        case 8:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "FoxAndMountainEasy (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 8; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1350118300;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end

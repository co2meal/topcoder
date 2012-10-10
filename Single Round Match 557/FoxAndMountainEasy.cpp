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

class FoxAndMountainEasy {
    public:
    string possible(int n, int h0, int hn, string history) {
        int need= 0;
        int delta = 0;
        for (int i = 0; i < history.size(); ++i)
        {
            if (history[i] == 'D') delta --;
            else delta ++;

            if (h0 + delta < 0)
                need = max(need, -h0-delta);
        }

        int count = n - (need + history.size());
        int remain = (hn - h0) - (need + delta);

        cout << need << " , " << delta <<endl;
        cout << count << " , " << remain <<endl;
        if (count < 0) return "NO";
        if (count >= abs(remain) && (count - remain) % 2 == 0) return "YES";
        else return "NO";

        return "";
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

        // Your custom testcase goes here
        case 7:
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
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1349881824;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end

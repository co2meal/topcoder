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

class ChocolateBar {
    public:
    int maxLength(string letters) {
        int res = 0;
        for (int i = 0; i < letters.size(); ++i) for (int j = i; j < letters.size(); ++j)
        {
            string temp = letters.substr(i, j-i + 1);
            sort(temp.begin(), temp.end());
            if (temp.end() == unique(temp.begin(), temp.end())) res = max(res, (int)temp.length());
        }
        return res;
    }
};

// CUT begin

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }



bool do_test(string letters, int expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    ChocolateBar instance;
    int result = instance.maxLength(letters);
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
            string letters = "srm";
            int expected = 3;
            return do_test(letters, expected, no);
        }
        case 1: {
            string letters = "dengklek";
            int expected = 6;
            return do_test(letters, expected, no);
        }
        case 2: {
            string letters = "haha";
            int expected = 2;
            return do_test(letters, expected, no);
        }
        case 3: {
            string letters = "www";
            int expected = 1;
            return do_test(letters, expected, no);
        }
        case 4: {
            string letters = "thisisansrmbeforetopcoderopenfinals";
            int expected = 9;
            return do_test(letters, expected, no);
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
    cout << "ChocolateBar (250 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1349877884;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end

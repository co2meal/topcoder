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

class CutSticks {
    public:

    bool avail(vector<int>& sticks, int C, int K, double key){
        int pieces = 0;
        for (int i = 0; C >= 0 && i < sticks.size(); ++i)
        {
            int t = int(sticks[i] / key);
            if (t <= 0) continue;
            int cuts = min(C, t - 1);
            pieces += cuts + 1;
            C -= cuts;
        }
        // cout << key << " , " << pieces << " , " << C << " , " << K <<endl;
        return pieces >= K;
    }
    double maxKth(vector<int> sticks, int C, int K) {
        double left = 0, right = 1e9;

        int magic = 100;

        sort(sticks.begin(), sticks.end());
        reverse(sticks.begin(), sticks.end());


        // while(1);

        while(magic--) {
            double key = (right + left) / 2;
            if (avail(sticks, C, K, key)) {
                left = key;
                // cout << "GD" <<endl;
            } else {
                right = key;
                // cout << "FF" <<endl;
            }
        }
        return left;

        return 0.0;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }


bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }


bool do_test(vector<int> sticks, int C, int K, double expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    CutSticks instance;
    double result = instance.maxKth(sticks, C, K);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;

    if (double_equal(expected, result)) {
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
            int sticks[] = {
                5, 8
            };
            int C = 1;
            int K = 1;
            double expected = 8.0;
            return do_test(to_vector(sticks), C, K, expected, no);
        }
        case 1: {
            int sticks[] = {
                5, 8
            };
            int C = 1;
            int K = 2;
            double expected = 5.0;
            return do_test(to_vector(sticks), C, K, expected, no);
        }
        case 2: {
            int sticks[] = {
                5, 8
            };
            int C = 1;
            int K = 3;
            double expected = 4.0;
            return do_test(to_vector(sticks), C, K, expected, no);
        }
        case 3: {
            int sticks[] = {
                1000000000, 1000000000, 1
            };
            int C = 2;
            int K = 5;
            double expected = 1.0;
            return do_test(to_vector(sticks), C, K, expected, no);
        }
        case 4: {
            int sticks[] = {
                76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49
            };
            int C = 789;
            int K = 456;
            double expected = 34.92;
            return do_test(to_vector(sticks), C, K, expected, no);
        }

        // Your custom testcase goes here
        case 5: {
            int sticks[] = {
                4,3,2,1
            };
            int C = 2;
            int K = 2;
            double expected = 3;
            return do_test(to_vector(sticks), C, K, expected, no);
            break;
        }
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "CutSticks (450 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1349873157;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end

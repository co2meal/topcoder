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


class Incubator {
    public:
    vector<string> love;
    bool visit[50];
    bool edge[50][50];
    int p[50];

    bool flow(int u) {
        if (visit[u]) return false;
        visit[u] = true;
        for (int v = 0; v < love.size(); ++v) if (edge[u][v])
        {
            if (p[v] == -1 || flow(p[v]))
            {
                p[v] = u;
                return true;
            }
        }
        return false;
    }

    int bpm() {
        memset(p, -1, sizeof p);

        int res = 0;
        for (int i = 0; i < love.size(); ++i)
        {
            memset(visit, false, sizeof visit);
            res += flow(i);
        }
        return res;
    }

    int maxMagicalGirls(vector<string> _love) {
        love = _love;
        memset(edge, false, sizeof edge);
        for (int i = 0; i < love.size(); ++i)
        {
            for (int j = 0; j < love[i].length(); ++j)
            {
                edge[i][j] = love[i][j] == 'Y';
            }
        }

        for (int k = 0; k < love.size(); ++k)
        {
            for (int i = 0; i < love.size(); ++i)
            {
                for (int j = 0; j < love.size(); ++j)
                {
                    edge[i][j] |= edge[i][k] & edge[k][j];
                }
            }
        }

        return love.size() - bpm();

        return 0;
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }



bool do_test(vector<string> love, int expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    Incubator instance;
    int result = instance.maxMagicalGirls(love);
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
            string love[] = {
                "NY",
                "NN"
            };
            int expected = 1;
            return do_test(to_vector(love), expected, no);
        }
        case 1: {
            string love[] = {
                "NYN",
                "NNY",
                "NNN"
            };
            int expected = 1;
            return do_test(to_vector(love), expected, no);
        }
        case 2: {
            string love[] = {
                "NNYNN",
                "NNYNN",
                "NNNYY",
                "NNNNN",
                "NNNNN"
            };
            int expected = 2;
            return do_test(to_vector(love), expected, no);
        }
        case 3: {
            string love[] = {
                "NNNNN",
                "NYNNN",
                "NYNYN",
                "YNYNN",
                "NNNNN"
            };
            int expected = 2;
            return do_test(to_vector(love), expected, no);
        }
        case 4: {
            string love[] = {
                "NNNNN",
                "NNNNN",
                "NNNNN",
                "NNNNN",
                "NNNNN"
            };
            int expected = 5;
            return do_test(to_vector(love), expected, no);
        }
        case 5: {
            string love[] = {
                "NNYNNNNN",
                "NNNYNNNN",
                "NNNNYNNN",
                "NNYNNNNN",
                "NNNNNYYN",
                "NNNYNNNY",
                "NNNNNNNN",
                "NNNNNNNN"
            };
            int expected = 2;
            return do_test(to_vector(love), expected, no);
        }
        case 6: {
            string love[] = {
                "Y"
            };
            int expected = 0;
            return do_test(to_vector(love), expected, no);
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
    cout << "Incubator (550 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 7; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1350117131;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end

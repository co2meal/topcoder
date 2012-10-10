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


// Wrong solution

using namespace std;

class Incubator {
    public:

    vector<string> love;

    bool visit[50];
    int cN;
    int arr[50];
    vector< vector<int> > cV;
    int cC[50];
    bool cE[50][50];

    void DFS1(int u) {
        if(visit[u]) return;
        visit[u] = true;
        arr[cN++] = u;

        for (int v = 0; v < love[u].size(); ++v)
        {
            if (love[u][v] == 'N') continue;
            DFS1(v);
        }

    }

    void DFS2(int u) {
        if(visit[u]) return;
        visit[u] = true;
        cC[u] = cN;
        cV[cN].push_back(u);

        for (int v = 0; v < love[u].size(); ++v)
        {
            if (love[v][u] == 'N') continue;
            DFS2(v);
        }
    }


    int maxMagicalGirls(vector<string> _love) {
        love = _love;

        cN = 0;
        memset(visit, false, sizeof visit);
        for (int i = 0; i < love.size(); ++i)
        {
            DFS1(i);
        }

        reverse(arr, arr+love.size());
        cN = 0;
        memset(visit, false, sizeof visit);
        cV.empty();
        for (int u = 0; u < love.size(); ++u)
        {
            if (visit[u]) continue;
            cV.push_back( vector<int>());
            DFS2(u);
            cN++;
        }

        memset(cE, false, sizeof cE);

        for (int i = 0; i < cV.size(); ++i)
        {
            for (int j = 0; j < cV[i].size(); ++j)
            {
                int u = cV[i][j];
                for (int v = 0; v < love[u].size(); ++v)
                {
                    if (love[u][v] == 'N') continue;
                    int cu = i;
                    int cv = cC[v];

                    cE[cu][cv] = true;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < cV.size(); ++i)
        {
            cout << cV[i].size() << endl;
            int head = 0;
            for (int u = i; u < cV.size(); ++u)
            {
                bool ishead = 1;
                for (int v = i; v < cV.size(); ++v)
                {
                    if (cE[v][u]) ishead = false;
                }
                if (ishead) head += cV[u].size();
            }

            res = max(res, head);
        }
        return res;
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
        case 7: {
            string love[] = {
                "NYNNNNNNN",
                "NNYNNNNNN",
                "YNNYNNNNN",
                "NNNNYNNNN",
                "NNNNNYNNN",
                "NNNNNNYNN",
                "NNNYNNNYN",
                "NNNNNNNNY",
                "NNNNNNNYN"
            };
            int expected = 0;
            return do_test(to_vector(love), expected, no);
            break;
        }
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
        for (int i = 0; i < 8; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1349883441;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 550 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end

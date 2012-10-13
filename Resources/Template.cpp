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

class ${ClassName} {
    public:
    ${Method.ReturnType} ${Method.Name}(${Method.Params}) {
        return ${Method.ReturnType;ZeroValue};
    }
};

${CutBegin}
${<TestCode}
${CutEnd}
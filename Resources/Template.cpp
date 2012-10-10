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

class ${ClassName} {
    public:
    ${Method.ReturnType} ${Method.Name}(${Method.Params}) {
        return ${Method.ReturnType;ZeroValue};
    }
};

${CutBegin}
${<TestCode}
${CutEnd}
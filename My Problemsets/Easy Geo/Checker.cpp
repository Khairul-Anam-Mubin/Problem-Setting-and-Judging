/**
 * Checker to compare output and answer in the form:
 *
 * Case 1: <number>
 * Case 2: <number>
 * ...
 * Case n: <number>
 *
 */

#include "testlib.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

using namespace std;

vector<double> readStream(InStream& in, TResult pe)
{
    vector<double> result;

    for (int testCase = 1; !in.seekEof(); testCase++)
    {
        //string caseStr = in.readToken();
        //if (caseStr != "Case")
            //quitf(pe, "Expected 'Case' but found '%s' [test case %d]", compress(caseStr).c_str(), testCase);

        //string numExpStr;
        //stringstream ss;
        //ss << testCase;
        //ss >> numExpStr;
        //numExpStr += ":";
        //string numStr = in.readToken();
        //if (numExpStr != numStr)
            //quitf(pe, "Expected '%s' but found '%s' [test case %d]", compress(numExpStr).c_str(), compress(numStr).c_str(), testCase);

        result.push_back(in.readDouble());
    }

    return result;
}

int main(int argc, char* argv[])
{
    setName("Single int64 checker with testcase-support");
    registerTestlibCmd(argc, argv);

    
    vector<double> ja = readStream(ans, _fail);
    vector<double> pa = readStream(ouf, _pe);
    
    if (ja.size() != pa.size()) quitf(_wa, "wrong");
    for (int i = 0; i < ja.size(); i++) {
        if (abs(ja[i] - pa[i]) >= 1e-6) quitf(_wa, "wrong");
    }
    quitf(_ok,"ok");
}
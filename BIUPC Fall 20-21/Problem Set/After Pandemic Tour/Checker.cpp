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

int Strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
vector<int> readStream(InStream& in, TResult pe , int cases)
{
    vector<int> result;

    for (int testCase = 1; cases; testCase++ , cases--)
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

        result.push_back(Strtoint(in.readToken()));
    }

    return result;
}

int main(int argc, char* argv[])
{
    setName("Single int64 checker with testcase-support");
    registerTestlibCmd(argc, argv);

    string a = inf.readToken() ;
    string b = inf.readToken() ;
    int m = Strtoint(b);
    vector<int> ja = readStream(ans, _fail , m);
    vector<int> pa = readStream(ouf, _pe , m);
    
    if ((ja.size() != pa.size()) || (pa.size() == 0)) quitf(_wa, "wrong");
    for (int i = 0; i < ja.size(); i++) {
        if (ja[i] != pa[i]) quitf(_wa, "wrong");
    }
    quitf(_ok,"ok");
}
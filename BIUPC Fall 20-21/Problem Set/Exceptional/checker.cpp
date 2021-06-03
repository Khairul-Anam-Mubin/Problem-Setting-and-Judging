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

char Uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
int main(int argc, char* argv[])
{
    setName("Single int64 checker with testcase-support");
    registerTestlibCmd(argc, argv);
    string s = ouf.readString();
    for (int i = 0; i < (int)s.size(); i++) {
        s[i] = Uplowch(s[i]);
    }
    if (s == "hello world") {
        quitf(_wa, "wrong");
    }
    quitf(_ok,"ok");
}
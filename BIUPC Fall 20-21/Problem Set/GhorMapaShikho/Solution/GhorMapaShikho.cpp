#include<bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("SampleOutput2.txt", "w", stdout);
    int nUmber;
    long long feet, inches, totalFeet = 0, totalInches = 0;
    char c;
    cin>> nUmber;
    while(nUmber)
    {
        cin>> feet >> c >> inches;
        totalFeet += feet;
        totalInches += inches;
        if(totalInches >= 12)
        {
            totalFeet += totalInches/12;
            totalInches %= 12;

        }
        printf("%lld Feet, %lld Inches\n", totalFeet, totalInches);
        nUmber--;
    }

}

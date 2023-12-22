#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string wantedStr;
    cin >> wantedStr;
    string currStr;
    cin >> currStr;
    int counter = 0;
    int size = currStr.size();
    int size1 = wantedStr.size();
    for(size_t i = 0; i < size; i++)
    {
        bool broken = false;
        for(size_t j = 0; j < size1; j++)
        {
            if(currStr[i + j] != wantedStr[j])
            {
                broken = true;
                break;
            }
        }
        if(!broken)
        {
            counter++;
        }
    }
    cout << counter;
    return 0;
}

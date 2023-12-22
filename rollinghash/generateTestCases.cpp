#include <format>
#include <bits/stdc++.h>
#include <string_view>

using namespace std;
typedef long long ll;

void generateTestCase(string filename, int size1, int size2) {

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> char_(97, 122);
    uniform_int_distribution<std::mt19937::result_type> bit(0, 2);

    ofstream myfile;
    myfile.open(filename);

    string str1;
    for (int i = 0; i < size1; i++) {
        char in = (char) char_(rng);
        str1 += in;
        myfile << in;
    }
    myfile << '\n';
    int i = 0;
    while(i < size2) {
        if (bit(rng) == 0) {
            myfile << str1;
            i += size1;
        } else {
            myfile << (char) char_(rng);
            i++;
        }
    }


    myfile.close();
}

int main() {

    srand (time(NULL));
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> size_(700000, 1000000);
    //uniform_int_distribution<std::mt19937::result_type> big_size(90000, 100000);

    string inputBase = "input";
    for (int i = 0; i <= 20; i++) {
        
        int size1 = size_(rng);
        int size2 = size1 + (rand() % (100000 - size1));
        cout << "SIZE1: " << size1 << '\n';
        cout << "SIZE2: " << size2 << '\n';
        generateTestCase((inputBase + (i < 10 ? "0" + to_string(i) : to_string(i)) + ".txt"), size1, size2);
    }

}

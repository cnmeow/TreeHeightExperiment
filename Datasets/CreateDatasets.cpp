#include <bits/stdc++.h>
using namespace std;
int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> randomN(990000, 1000000); // Min-max of N (~10^6)
    uniform_int_distribution<int> randomNumber(10000, 10000000); // Min-max of elements in tree

    for (int i = 1; i <= 10; ++i) {
        string filename = "dataset" + std::to_string(i) + ".txt"; // Name of dataset file
        ofstream file(filename);
        int N = randomN(gen);
        file << N <<'\n';

        unordered_set<int> uniqueNumbers;
        while (uniqueNumbers.size() < N) {
            uniqueNumbers.insert(randomNumber(gen));
        }
        for (const int& num : uniqueNumbers) {
            file << num << ' ';
        }

        file.close();
    }
    return 0;
}

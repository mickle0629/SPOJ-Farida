#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
int maxCoins(std::vector<int> monsters) {
    if (monsters.size() == 2) {
        return std::min(monsters[0], monsters[1]);
    }
    else if (monsters.size() == 1) {
        return monsters[0];
    } else if (monsters.empty()) {
        return 0;
    }
    std::map<int, int> dp;
    dp[0] = monsters[0];
    dp[1] = monsters[1];
    
    for (int i = 2; i < monsters.size(); i++) { // for every monster starting from the 3rd one
        dp[i] = std::max((monsters[i] + dp[i - 2]), dp[i - 1]); // Compute the dp value for that monster
    }
        // return value
    return dp[dp.size() - 1];
}

int main() {
    bool testing = false;
    if (testing) {
        std::vector<int> monsters = {};
        std::cout << maxCoins(monsters) << std::endl;
    }
    
    else {
        int noTestCases = 0;
        std::cin >> noTestCases;
        std::vector<int> results = {};

        for (int i = 0; i < noTestCases; i++) {
            int arrayLength;
            std::cin >> arrayLength;
            std::vector<int> inputArray = {};

            for (int i = 0; i < arrayLength; i++) {
                int input;
                std::cin >> input;
                inputArray.push_back(input);
            }

            results.push_back(maxCoins(inputArray));
        }
        for (int i = 0; i < results.size(); i++) {
            std::cout << "Case " << i + 1 << ": " << results[i] << std::endl;
        }
    }
    return 0;
}
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
int maxCoins(std::vector<int> monsters) {
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
    printf("Hello World");
    std::vector<int> monsters = {1,2,3,4,5};
    std::cout << maxCoins(monsters) << std::endl;
    return 0;
}
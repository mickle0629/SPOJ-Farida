#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
int maxCoins(std::vector<int> monsters) {
    std::map<int, int> dp;
    dp[monsters[0]] = monsters[0];
    dp[monsters[1]] = monsters[1];
    // for every monster starting from the 3rd one
    for (int i = 2; i < monsters.size(); i++) {
        dp[monsters[i]] = std::max((monsters[i] + dp[monsters[i - 2]]), dp[monsters[i - 1]]);
    }
        // Compute the dp value for that monster
        
        // return value
        return 0;
}

int main() {
    printf("Hello World");
    std::vector<int> monsters = {25,1,45,42,1,8,9};
    maxCoins(monsters);
    return 0;
}
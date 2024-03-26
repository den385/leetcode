// Given an array of integers nums and an integer target, return two numbers of nums such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// You can return the answer in any order.
//
//  Samples:
//
// Input : nums = [ 2, 7, 11, 15 ], target = 9 
// Output : [ 2, 7 ] Explanation : Because 2 + 7 == 9, we return [ 2, 7 ]
//
// Input : nums = [ 3, 2, 4 ], target = 6 
// Output : [ 2, 4 ] 
//
// Input : nums = [ 3, 3 ], target = 6 
// Output : [ 3, 3 ]

#include <iostream>
#include <vector>
#include <unordered_map>

std::pair<int, int> getComplementaryValues(std::vector<int> numbers, int target)
{
    std::unordered_map<int, int> numCount; // because it mb 1 or 2
    
    for (auto n : numbers)
    {
        numCount[n] += 1;
        
        if ((target != 2*n) && numCount[target - n] >= 1)
            return {n, target - n};
        else if ((target == 2*n) && numCount[target - n] >= 2)
            return {n, n};
    }
    
    return {0, 0}; // error
}


int main()
{
    std::vector<int> numbers;
    
    char c;
    while (c != '[')
        std::cin >> c;
    
    int i;
    std::string sNum;
    while (c != int(']'))
    {
        std::cin >> c;
        numbers.push_back(i);
    }
    
    while (c != '=')
        std::cin >> c;
    
    int target{};
    std::cin >> target;
    
    // for (auto n : numbers)
    //     std::cout << n;
    // std::cout << target;
    
    auto answer = getComplementaryValues(numbers, target);
    
    std::cout << target << " " << answer.first << " " << answer.second;

    return 0;
}


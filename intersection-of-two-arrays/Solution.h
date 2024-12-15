//
// Created by stuar on 15/12/2024.
//

#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <vector>
#include <map>

namespace intersection_of_two_arrays {

    class Solution {
    public:
        static std::vector<int> intersection1(std::vector<int>& nums1, std::vector<int>& nums2) {
            auto numberCount = std::map<int, std::pair<int, int>>{};

            for (auto num1 : nums1)
            {
                numberCount[num1].first++;
            }
            for (auto num2 : nums2)
            {
                numberCount[num2].second++;
            }

            std::vector<int> common;
            for (const auto& [number, values] : numberCount)
            {
                std::cout << number << " : " << values.first << ", " << values.second << '\n';
                if (values.first && values.second)
                {
                    common.push_back(number);
                }
            }

            return common;
        }

        static std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
            auto numberCount = std::map<int, bool>{};

            for (auto num1 : nums1)
            {
                numberCount[num1] = true;
            }

            std::vector<int> result;

            for (auto num2 : nums2)
            {
                if (numberCount.contains(num2) && numberCount[num2])
                {
                    result.push_back(num2);
                    numberCount[num2] = false;
                }
            }

            return result;
        }
    };

} // intersection_of_two_arrays

#endif //SOLUTION_H

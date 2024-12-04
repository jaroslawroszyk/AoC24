#include "include/day01.hpp"
#include <iostream>
#include <numeric>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>
#include "utilities.hpp"

namespace
{
auto parseInput(const std::string& input) -> std::pair<std::vector<int>, std::vector<int>>
{
    auto lines = utils::lines(input);
    std::vector<int> leftNumbers{};
    std::vector<int> rightNumbers{};

    for (const auto& line : lines)
    {
        std::istringstream lineStream(line);
        int left, right = 0;
        lineStream >> left >> right;

        leftNumbers.push_back(left);
        rightNumbers.push_back(right);
    }
    std::ranges::sort(leftNumbers);
    std::ranges::sort(rightNumbers);

    return {leftNumbers, rightNumbers};
}
} // namespace

auto solvePartOne(const std::string& input) -> int
{
    int totalDist{0};
    auto [leftNumbers, rightNumbers] = parseInput(input);
    for (int i = 0; i < leftNumbers.size(); ++i)
    {
        totalDist += std::abs(leftNumbers[i] - rightNumbers[i]);
    }
    return totalDist;
}

auto solvePartTwo(const std::string& input) -> int
{
    // v1
    // auto [leftNumbers, rightNumbers] = parseInput(input);
    // std::unordered_map<int,int> rightCounts;

    // for (int right : rightNumbers)
    // {
    //     rightCounts[right]++;
    // }

    // int sum{0};
    // for(int left : leftNumbers)
    // {
    //     sum += left * rightCounts[left];
    // }
    // return sum;

    // v2
    auto [leftNumbers, rightNumbers] = parseInput(input);

    std::unordered_map<int, int> rightCounts;
    for (int right : rightNumbers)
    {
        rightCounts[right]++;
    }

    return std::transform_reduce(
        leftNumbers.begin(),
        leftNumbers.end(),
        0,
        std::plus<>{},
        [&rightCounts](int left) { return left * rightCounts[left]; });
}

auto Day01::part_one(const std::string& input) -> std::string // 2367773
{
    auto result = solvePartOne(input);
    constexpr auto expectedRes{2367773};

    assert(result == expectedRes); // add flag to that for enabling asserting

    return std::to_string(result);
}

auto Day01::part_two(const std::string& input) -> std::string // 21271939
{
    auto result = solvePartTwo(input);
    constexpr auto expectedRes{21271939};

    assert(result == expectedRes); // add flag to that for enabling asserting

    return std::to_string(result);
}

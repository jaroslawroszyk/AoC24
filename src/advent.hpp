#include <cassert>
#include <iostream>
#include <memory>

#include "days/Puzzle.hpp"
#include "inc/days.inc"

namespace advent
{
auto puzzle(int day) -> std::unique_ptr<Puzzle>
{
    assert(0 < day and day < 26);

    switch (day)
    {
        case 1:
            return std::make_unique<Day01>(Day01());
        default:
            std::cout << "ops";
            return nullptr;
    }
}
} // namespace advent

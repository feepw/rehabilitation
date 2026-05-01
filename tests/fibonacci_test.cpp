#include <unordered_map>
#include <limits>

#include "gtest/gtest.h"

#include "rehabilitation/fibonacci.h"

TEST(FibonacciTests, TestBasicSequences) {
  const std::unordered_map<int, int> data{
      {0, 0},
      {1, 1},
      {2, 1},
      {3, 2},
      {4, 3},
      {5, 5},
      {6, 8},
      {7, 13},
      {8, 21},
      {9, 34},
      {10, 55}
  };
  for (auto ci = data.cbegin(), ce = data.cend(); ci != ce; ci++) {
    EXPECT_EQ(rehabilitation::fibonacci(ci->first), ci->second);
  }
}

TEST(FibonacciTests, TestException) {
  EXPECT_THROW(rehabilitation::fibonacci(-1), std::invalid_argument);
  EXPECT_THROW(rehabilitation::fibonacci<std::uint16_t>(
                   std::numeric_limits<std::int16_t>::max()),
               std::overflow_error);
}

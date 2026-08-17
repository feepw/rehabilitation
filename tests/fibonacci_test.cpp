#include <stdexcept>
#include <unordered_map>

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
    EXPECT_EQ(rehabilitation::fibonacci::fibonacci(ci->first), ci->second);
  }
}

TEST(FibonacciTests, TestException) {
  // static_cast<void> explicitly discards the [[nodiscard]] return value.
  EXPECT_THROW(static_cast<void>(rehabilitation::fibonacci::fibonacci(-1)),
               std::overflow_error);
}

#include <unordered_map>

#include "gtest/gtest.h"

#include "rehabilitation/fibonacci.h"

TEST(FibonacciTests, TestBasicSequences) {
  const std::unordered_map<std::uint32_t, std::uint32_t> data{
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
    ASSERT_EQ(rehabilitation::fibonacci(ci->first), ci->second);
  }
}

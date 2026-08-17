#ifndef RH_FIBONACCI_V2_H
#define RH_FIBONACCI_V2_H

#include <limits>
#include <stdexcept>

namespace rehabilitation::fibonacci_v2 {

/**
 * @brief Compute the n-th Fibonacci number.
 *
 * Uses an iterative dynamic-programming approach with O(index) time
 * and O(1) auxiliary space.
 *
 * The Fibonacci sequence is defined as:
 *   F(0) = 0
 *   F(1) = 1
 *   F(n) = F(n-1) + F(n-2) for n >= 2
 *
 * @param index The zero-based index in the Fibonacci sequence.
 * @return The Fibonacci number F(index).
 * @throws std::overflow_error If F(index) does not fit in std::size_t.
 */
[[nodiscard]]
constexpr auto fibonacci(std::size_t index) -> std::size_t {
  if (index <= 1) {
    return index;
  }

  std::size_t current{1};
  std::size_t previous{0};
  for (std::size_t i{1}; i < index; ++i) {
    if (std::numeric_limits<std::size_t>::max() - current < previous) {
      throw std::overflow_error("fibonacci result overflows std::size_t");
    }
    const std::size_t next = current + previous;
    previous = current;
    current = next;
  }
  return current;
}

}  // namespace rehabilitation::fibonacci_v2

#endif

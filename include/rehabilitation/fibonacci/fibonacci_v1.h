#ifndef RH_FIBONACCI_V1_H
#define RH_FIBONACCI_V1_H

#include <limits>
#include <stdexcept>

namespace rehabilitation::fibonacci_v1 {

/**
 * @brief Compute the n-th Fibonacci number.
 *
 * The Fibonacci sequence is defined as:
 *   F(0) = 0
 *   F(1) = 1
 *   F(n) = F(n-1) + F(n-2) for n >= 2
 *
 * This is a direct recursive implementation. It has exponential time
 * complexity O(2^n) and O(n) recursion depth. It is suitable for small
 * indices and compile-time evaluation; for large indices use an iterative
 * or memoized algorithm instead.
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

  const auto previous = fibonacci(index - 1);
  const auto before_previous = fibonacci(index - 2);

  if (previous > std::numeric_limits<std::size_t>::max() - before_previous) {
    throw std::overflow_error("fibonacci result overflows std::size_t");
  }

  return previous + before_previous;
}

}  // namespace rehabilitation::fibonacci_v1

#endif

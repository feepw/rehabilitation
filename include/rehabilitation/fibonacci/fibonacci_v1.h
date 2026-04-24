#ifndef RH_FIBONACCI_V1_H
#define RH_FIBONACCI_V1_H

#include <limits>
#include <stdexcept>

namespace rehabilitation::fibonacci_v1 {

constexpr std::size_t fibonacci(std::size_t index) {
  if (index == 0 || index == 1) {
    return index;
  }

  std::size_t result{1};
  std::size_t old{0};
  for (std::size_t i{1}; i < index; ++i) {
    if (std::numeric_limits<std::size_t>::max() - result < old) {
      throw std::overflow_error(
          "fibonacci sequence index too large for std::size_t");
    }
    std::size_t tmp{old};
    old = result;
    result += tmp;
  }
  return result;
}

}  // namespace rehabilitation::fibonacci_v1

#endif

#ifndef REHABILITATION_FIBONACCI_H
#define REHABILITATION_FIBONACCI_H

#include <stdexcept>

namespace rehabilitation {

template <typename RESULT_TYPE = uint, typename INPUT_TYPE>
constexpr RESULT_TYPE fibonacci(INPUT_TYPE x) {
  if (x < 0) {
    throw(std::invalid_argument("fibonacci forbid negative input"));
  }
  if (x == 0 || x == 1) {
    return x;
  }

  // start at 2
  RESULT_TYPE ret = 1;
  for (RESULT_TYPE pre = 1, tmp = 0; x > 2; x--) {
    tmp = pre;
    pre = ret;
    ret += tmp;
    if (ret < pre) {
      throw std::overflow_error("fibonacci calculation caused overflow");
    }
  }
  return ret;
}

}  // namespace rehabilitation

#endif  // REHABILITATION_FIBONACCI_H

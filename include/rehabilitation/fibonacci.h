#ifndef REHABILITATION_FIBONACCI_H
#define REHABILITATION_FIBONACCI_H

#include <stdexcept>
#include <type_traits>

namespace rehabilitation {

template <typename ResultT = unsigned int,
          typename InputT,
          typename = std::enable_if_t<std::is_integral<ResultT>::value &&
                                      std::is_integral<InputT>::value>>
constexpr ResultT fibonacci(InputT x) {
  if (x < 0) {
    throw std::invalid_argument("fibonacci forbid negative input");
  }
  if (x == 0 || x == 1) {
    return x;
  }

  // start at 2
  ResultT ret = 1;
  for (ResultT pre = 1, tmp = 0; x > 2; x--) {
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

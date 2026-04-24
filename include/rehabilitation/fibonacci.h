#include <cstdint>

constexpr std::uint32_t fibonacci(int x) {
  if (x == 0 || x == 1) {
    return x;
  }

  // start at x = 2
  std::uint32_t ret = 1;
  for (std::uint32_t pre = 1, tmp = 0; x > 2; x--) {
    tmp = pre;
    pre = ret;
    ret += tmp;
  }
  return ret;
}

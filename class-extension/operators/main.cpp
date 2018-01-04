#include "comparable.h"

#include <cassert>
#include <cstdio>

auto main(const int /*argc*/, const char *const []/*argv*/) -> int
{
  auto a{comparable{-1}};
  auto b{comparable{0}};
  auto c{comparable{1}};
  auto c2{comparable{1}};
  assert(a != b);
  assert(a < b);
  assert(a <= b);
  assert(c > b);
  assert(c >= b);
  assert(c == c2);
  assert(c <= c2);
  assert(c >= c2);
  return 0;
}

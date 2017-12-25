#include "some_derived.h"
#include <cstdio>

auto main(const int /*argc*/, const char *const /*argv*/) -> int
{
  auto d{ some_derived{} };
  d.baz();

  d.bar();  //compiler now instantiates base<some_derived>::bar()

  printf("Hello, CRTP!\n");
  return 0;
}

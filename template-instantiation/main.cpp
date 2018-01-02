#include "template.h"
#include <cstdio>

auto main(const int /*argc*/, const char *const []/*argv*/) -> int
{
  auto tc{ template_class<int>{} };

  tc.called();
  //tc.not_called();

  printf("Hello, templates!\n");

  return 0;
}

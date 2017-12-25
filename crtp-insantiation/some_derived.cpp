#include "some_derived.h"
#include <cstdio>

auto some_derived::baz() -> void
{
  printf("baz()\n");
}

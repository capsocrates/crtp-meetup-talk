#pragma once
#include <cstdio>

template<typename derived>
class base
{
public:
  auto foo() -> void { printf("foo()\n"); }
  auto bar() -> void { printf("bar()\n"); }
};

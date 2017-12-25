#pragma once
#include <cstdio>
template<typename template_arg>
class template_class
{
public:
  auto called() -> void {
    printf("template_class<>::called()\n");
  }
  auto not_called() -> void {
    printf("template_class<>::not_called()\n");
  }
};

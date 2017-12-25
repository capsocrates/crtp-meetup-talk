#pragma once

#include "base.h"

class some_derived : public base<some_derived>
{
public:
  auto baz() -> void;
};

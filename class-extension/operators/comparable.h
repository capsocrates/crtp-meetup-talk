#pragma once

#include "equivalent.h"

class comparable : public equivalent<comparable>
{
  int value;
public:
  comparable(const int val) : value{val} {}
  friend auto operator<(const comparable &lhs, const comparable &rhs) -> bool {
    return lhs.value < rhs.value;
  }
};

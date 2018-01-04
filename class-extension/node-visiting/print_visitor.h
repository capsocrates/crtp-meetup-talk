#pragma once

#include "generic_visitor.h"

#include <cassert>
#include <iostream>
#include <string>

class print_visitor : public generic_visitor<print_visitor>
{
  std::string separator;
public:
  print_visitor(std::string sep = "\n") : separator(std::move(sep)) {}
  auto visit(int* value) -> void { assert(value); std::cout << *value << separator; }
};
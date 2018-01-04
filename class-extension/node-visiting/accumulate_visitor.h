#pragma once

#include "generic_visitor.h"

#include <cassert>
#include <string>

class accumulate_visitor : public generic_visitor<accumulate_visitor>
{
  std::string separator;
  std::string value;
public:
  accumulate_visitor(std::string sep = "\n", std::string initial_val = {}) : separator(std::move(sep)), value(std::move(initial_val)) {}
  auto visit(std::string* val) -> void { assert(val); value += *val; value += separator; }
  auto get_value() const -> std::string { return value; }
  auto reset() -> void { value.clear(); }
};

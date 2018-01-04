#pragma once

#include <memory>
template<typename derived>
class singleton
{
  singleton(const singleton&) = delete;
  auto operator=(const singleton&) -> singleton& = delete;
protected:
  static std::unique_ptr<derived> obj;
  singleton() = default;
public:
  static auto get() -> derived& {
    if(!obj) {
      obj = std::unique_ptr<derived>(new derived{});
    }
    return *obj;
  }
};
template<typename derived>
std::unique_ptr<derived> singleton<derived>::obj = nullptr;

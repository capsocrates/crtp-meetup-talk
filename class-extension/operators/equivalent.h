#pragma once

template<class derived>
struct equivalent {
  auto ref() -> derived& { return *static_cast<derived *>(this); }
  auto ref() const -> const derived& { return *static_cast<const derived *const>(this); }
};
template<class derived>
auto operator<(const equivalent<derived> &lhs, const equivalent<derived> &rhs) -> bool {
  return lhs.ref() < rhs.ref();
}
template<class derived>
auto operator==(const equivalent<derived> &lhs, const equivalent<derived> &rhs) -> bool {
  return !(lhs < rhs) && !(rhs < lhs);
}
template<class derived>
auto operator!=(const equivalent<derived> &lhs, const equivalent<derived> &rhs) -> bool {
  return !(lhs==rhs);
}
template<class derived>
auto operator<=(const equivalent<derived> &lhs, const equivalent<derived> &rhs) -> bool {
  return lhs < rhs || !(rhs < lhs);
}
template<class derived>
auto operator>(const equivalent<derived> &lhs, const equivalent<derived> &rhs) -> bool {
  return rhs < lhs;
}
template<class derived>
auto operator>=(const equivalent<derived> &lhs, const equivalent<derived> &rhs) -> bool {
  return lhs > rhs || !(rhs > lhs);
}

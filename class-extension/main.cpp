#include "singleton.h"

class only_one : public singleton<only_one>
{
  friend class singleton<only_one>;
  only_one() {
  }
};

auto main(const int /*argc*/, const char *const []/*argv*/) -> int
{
  auto& one = only_one::get();
  //only_one two{}; //won't compile; only_one constructor is private
  //auto three = only_one::get(); //won't compile, singletong<derived> copy operations are deleted
  printf("I made only one\n");
  return 0;
}
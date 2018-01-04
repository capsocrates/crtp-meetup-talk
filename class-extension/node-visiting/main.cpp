#include <iostream>

#include "tree.h"
#include "print_visitor.h"
#include "accumulate_visitor.h"

auto main(const int /*argc*/, const char *const []/*argv*/) -> int
{
  {
    auto tr{tree<int>{0}};
    tr.get_root_node()->add_left_child(1);
    tr.get_root_node()->add_right_child(2);

    auto printer{print_visitor{" "}};
    printer.prefix_visit<int>(tr.get_root_node());
    printer.infix_visit<int>(tr.get_root_node());
    printer.postfix_visit<int>(tr.get_root_node());
  }
  printf("\n");
  {
    auto str_tr{tree<std::string>{"-"}};
    str_tr.get_root_node()->add_left_child("1");
    str_tr.get_root_node()->add_right_child("2");
    str_tr.get_root_node()->left()->add_left_child("a");
    str_tr.get_root_node()->left()->add_right_child("b");
    str_tr.get_root_node()->right()->add_left_child("c");
    str_tr.get_root_node()->right()->add_right_child("d");
    auto printer{accumulate_visitor{" "}};
    printer.infix_visit<std::string>(str_tr.get_root_node());
    std::cout << printer.get_value() << '\n';
    // printer.reset();
    // printer.prefix_visit<std::string>(str_tr.get_root_node());
    // printer.postfix_visit<std::string>(str_tr.get_root_node());
    // std::cout << printer.get_value() << '\n';
  }

  return 0;
}
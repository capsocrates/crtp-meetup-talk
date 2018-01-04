#pragma once

#include "tree.h"

template<typename derived_visitor>
class generic_visitor {
private:
  template<typename type>
  auto do_visit(type* value) -> void {
    static_cast<derived_visitor*>(this)->visit(value);
  }
  template<typename type>
  auto do_visit(type* value) const -> void {
    static_cast<const derived_visitor* const>(this)->visit(value);
  }
public:
  template<typename type>
  auto prefix_visit(typename tree<type>::node *n) -> void {
    if(!n) return;
    do_visit(n->value());
    prefix_visit<type>(n->left());
    prefix_visit<type>(n->right());
  }
  template<typename type>
  auto infix_visit(typename tree<type>::node *n) -> void {
    if(!n) return;
    infix_visit<type>(n->left());
    do_visit(n->value());
    infix_visit<type>(n->right());
  }
  template<typename type>
  auto postfix_visit(typename tree<type>::node *n) -> void {
    if(!n) return;
    postfix_visit<type>(n->left());
    postfix_visit<type>(n->right());
    do_visit(n->value());
  }
};

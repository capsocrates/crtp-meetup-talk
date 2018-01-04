#pragma once

#include <memory>
template<typename type>
class tree {
public:
  class node {
    std::unique_ptr<type> m_value;
    std::unique_ptr<node> m_left;
    std::unique_ptr<node> m_right;
  public:
    node(type value) : m_value(std::make_unique<type>(std::move(value))) {}
    auto add_left_child(type value) -> void { m_left = std::make_unique<node>(std::move(value)); }
    auto add_right_child(type value) -> void { m_right = std::make_unique<node>(std::move(value)); }
    auto value() -> type* { return m_value.get(); }
    auto value() const -> const type* { return m_value.get(); };
    auto left() -> node* { return m_left.get(); };
    auto left() const -> const node* { return m_left.get(); };
    auto right() -> node* { return m_right.get(); };
    auto right() const -> const node* { return m_right.get(); };
  };
  tree(type root_value) : root_node{std::make_unique<node>(std::move(root_value))} {}
  auto get_root_node() -> node * { return root_node.get(); };
  auto get_root_node() const -> const node * const { return root_node.get(); };
private:
  std::unique_ptr<node> root_node;
};

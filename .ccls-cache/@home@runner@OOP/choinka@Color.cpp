#include "Tree.hpp"
enum class Color { Green, Yellow, Red };

void Tree::SetColor(Color color) {
  switch (color) {
    case Color::Green:
      this->color = "\033[1;35m";
      break;
    case Color::Yellow:
      this->color = "\033[1;33m";
      break;
    case Color::Red:
      this->color = "\033[1;31m";
      break;
  }
}

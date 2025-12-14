#include <iostream>
#include <stack>

std::string name;
std::stack<size_t> S, T;

int main() {
  size_t op, val;

  std::cout << "What's your name?" << std::endl;
  std::cin >> name;
  std::cout << "Hello, " << name << "!" << std::endl;

  while (std::cin.good()) {
    std::cin >> op;
    if (op == 1) {
      std::cin >> val;
      S.push(val);
    } else if (op == 2) {
      S.pop();
    } else if (op == 3) {
      std::cin >> val;
      T.push(val);
    } else if (op == 4) {
      T.pop();
    } else {
      break;
    }
  }

  return 0;
}

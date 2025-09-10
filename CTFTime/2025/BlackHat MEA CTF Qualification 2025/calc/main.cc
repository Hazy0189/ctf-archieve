#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, std::function<int(int, int)>> ops = {
  {"add", [](int a, int b) { return a + b; }},
  {"sub", [](int a, int b) { return a - b; }},
  {"mul", [](int a, int b) { return a * b; }},
  {"div", [](int a, int b) { return a / b; }},
  {"and", [](int a, int b) { return a & b; }},
  {"or" , [](int a, int b) { return a | b; }},
  {"xor", [](int a, int b) { return a ^ b; }},
};

int main() {
  std::vector<int> stack;
  std::string line;
  std::cin.rdbuf()->pubsetbuf(nullptr, 0);
  std::cout.rdbuf()->pubsetbuf(nullptr, 0);

  while (std::cin.good()) {
    std::cout << "--- Enter code ---" << std::endl;
    stack.resize(0);
    stack.shrink_to_fit();

    while (std::cin.good()) {
      std::cin >> std::setw(0x10) >> line;
      std::transform(line.begin(), line.end(), line.begin(), [](char c) {
        return std::tolower(c);
      });

      if (line == "end") {
        break;

      } else if (line == "quit") {
        return 0;

      } else if (ops.find(line) == ops.end()) {
        stack.push_back(std::stoi(line));

      } else {
        int b = stack.back();
        stack.pop_back();
        int a = stack.back();
        stack.pop_back();
        stack.push_back(ops[line](a, b));
      }
    }

    std::cout << "Result: " << stack.back() << std::endl;
  }

  return 0;
}

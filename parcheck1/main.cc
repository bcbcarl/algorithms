#include <iostream>
#include "parChecker.h"

void printResult(const std::string& s);

int main() {
  printResult("");
  printResult("()");
  printResult("(())");
  printResult("(()()()())");
  printResult("(((())))");
  printResult("(()((())()))");

  std::cout << "---" << std::endl;

  printResult("(* n n)");
  printResult("(()");
  printResult("())");
  printResult("((((((())");
  printResult("()))");
  printResult("(()()(()");

  return 0;
}

void printResult(const std::string& s) {
  carl::ParChecker checker;
  const auto result = checker.check(s) ? "True" : "False";
  std::cout << result << std::endl;
}

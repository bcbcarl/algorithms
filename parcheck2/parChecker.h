#ifndef CARL_PAR_CHECKER_H
#define CARL_PAR_CHECKER_H

#include <stack>
#include <string>

namespace carl {
  class ParChecker {
  public:
    ParChecker();
    bool check(const std::string& s) noexcept;
  private:
    bool isValidOpeningSymbol(const char& c) const noexcept;
    bool isValidClosingSymbol(const char& c) const noexcept;
    bool matches(const char& c1, const char& c2) const noexcept;
    std::stack<char> stack_;
    std::string openings_;
    std::string closings_;
  };

  ParChecker::ParChecker() {
    openings_ = "([{";
    closings_ = ")]}";
  }

  bool ParChecker::isValidOpeningSymbol(const char& c) const noexcept {
    return openings_.find_first_of(c) != std::string::npos;
  }

  bool ParChecker::isValidClosingSymbol(const char& c) const noexcept {
    return closings_.find_first_of(c) != std::string::npos;
  }

  bool ParChecker::matches(const char& c1, const char& c2) const noexcept {
    return openings_.find_first_of(c1) == closings_.find_first_of(c2);
  }

  bool ParChecker::check(const std::string& s) noexcept {
    if (s.empty()) {
      return true;
    }

    for (char c : s) {
      if (isValidOpeningSymbol(c)) {
        stack_.push(c);
        continue;
      }

      if (stack_.empty()) {
        return false;
        break;
      }

      if (!isValidClosingSymbol(c)) {
        return false;
        break;
      }

      if (!matches(stack_.top(), c)) {
        return false;
        break;
      }

      stack_.pop();
    }

    return stack_.empty();
  }
}

#endif // CARL_PAR_CHECKER_H

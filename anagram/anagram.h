#ifndef CARL_ANAGRAM_H
#define CARL_ANAGRAM_H

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

namespace carl {
  typedef std::map<char, int> Map;

  Map make_map(const std::string& str) {
    Map map;
    for (char c: str) {
      auto it = map.find(c);
      if (it == map.end()) {
        map[c] = 1;
      } else {
        ++it->second;
      }
    }
    return map;
  }

  bool anagram(const std::string& s1, const std::string& s2) {
    auto map1 = make_map(s1);
    auto map2 = make_map(s2);
    return std::equal(map1.begin(), map1.end(), map2.begin());
  }

  void print_result(const std::string& s1, const std::string& s2) {
    std::cout << "The strings '" << s1 << "' and '" << s2 << "' are "
              << (anagram(s1, s2) ? "" : "not ")
              << "anagrams." << std::endl;
  }
}

#endif // CARL_ANAGRAM_H

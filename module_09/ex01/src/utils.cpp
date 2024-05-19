#include "utils.h"
#include <cctype>
#include <stdexcept>
#include <string>

std::string trim(const std::string &str) {
  std::string::const_iterator start = str.begin();
  while (start != str.end() && std::isspace(*start)) {
    start++;
  }

  std::string::const_reverse_iterator end = str.rbegin();
  while (end.base() != start && std::isspace(*end)) {
    end++;
  }

  return std::string(start, end.base());
}

std::string trimInternSpaces(const std::string &str) {
  std::string newStr = "";

  std::string::const_iterator start = str.begin();
  while (start != str.end() && std::isspace(*start)) {
    start++;
  }

  std::string::const_reverse_iterator end = str.rbegin();
  while (end.base() != start && std::isspace(*end)) {
    end++;
  }

  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (!::isspace(*it)) {
      newStr += *it;
    }
  }

  return newStr;
}

bool isOp(char c) { return c == '+' || c == '-' || c == '/' || c == '*'; }

bool doubleDigit(const std::string &str) {
  std::string noSpace = trim(str);
  for (std::string::const_iterator it = noSpace.begin(); it != noSpace.end();
       ++it) {
    while (::isspace(*it)) {
      ++it;
    }
    if (::isdigit(*it) && ::isdigit(*(it + 1))) {
      return true;
    } else if (isOp(*it) && isOp(*(it + 1)))
      return true;
  }
  return false;
}

bool validateInput(const std::string &str) {
  if (str.empty()) {
    throw std::invalid_argument("How you wanna calculate 'nothing'?");
  } else if (doubleDigit(str)) {
    throw std::invalid_argument(
        "Only numbers between 0 and 9. And no double operators.");
  }

  std::string validate = trimInternSpaces(str);
  std::string::const_iterator it = validate.begin();

  for (std::string::const_iterator it = validate.begin(); it != validate.end();
       ++it) {
    if (::isdigit(*it) || isOp(*it)) {
      continue;
    } else {
      throw std::invalid_argument("Only number and operator allowed.");
    }
  }

  if (isOp(*it)) {
    throw std::invalid_argument("Operation cannot be ther first element.");
  } else if (std::isdigit(*it) && isOp(*(it + 1))) {
    throw std::invalid_argument("You need to use 'number number + Operation'");
  }

  return true;
}

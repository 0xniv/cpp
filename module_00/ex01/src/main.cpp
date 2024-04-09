#include "PhoneBook.hpp"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

void clearCin(void) {
  std::clearerr(stdin);
  std::cin.clear();
}

std::string prompt(void) {
  std::string user_input;

  std::cout << "Choose one option: " << std::endl;
  std::cout << "Type 'ADD' or 'SEARCH' a contact or 'EXIT' to close program."
            << std::endl;

  if (std::cin.eof() || std::cin.fail())
    clearCin();

  std::cin >> user_input;
  return user_input;
}

void handleInput(const std::string str, PhoneBook& book) {

  if (str == "ADD") {
		book.addContact();
  } else if (str == "SEARCH") {
    std::cout << "is search" << std::endl;
  } else if (str == "EXIT") {
    std::cout << "You lost your contacts forever..." << std::endl;
    exit(EXIT_SUCCESS);
  }
}
int main(void) {

  PhoneBook book;
  std::string input;

  std::cout << "Welcome to your lovely PhonoBook!" << std::endl;
  while (true) {
    input = prompt();
    handleInput(input, book);
  }

  return 0;
}
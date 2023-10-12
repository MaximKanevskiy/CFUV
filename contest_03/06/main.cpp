#include <iostream>
#include <string>
#include <map>

int main()
{
  std::map<std::string, int> user;

  int usersAmount;
  std::cin >> usersAmount;

  for (int i = 0; i < usersAmount; i++)
  {
    std::string login;
    int balance;

    std::getline(std::cin, login, ';');
    std::cin >> balance;
    login.replace(0, 1, "");
    user[login] = balance;
  }

  std::cin >> usersAmount;

  for (int i = 0; i < usersAmount; i++)
  {
    std::string name;
    std::cin >> name;
    std::cout << user[name] << ' ';
  }
}

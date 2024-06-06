//
//  HOMEWORK_1.cpp
//  HW3
//
//  Created by Anastasiya Charykova on 06.06.2024.
//

#include "HOMEWORK_1.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Address { // структура адреса
  std::string city;
  std::string street;
  std::string houseNumber;
  std::string apartmentNumber;
};

int main() {
  std::ifstream inFile("in.txt"); // открытие файла
  std::ofstream outFile("out.txt");
  if (!inFile.is_open() || !outFile.is_open()) { // проверка на открытие файла
    std::cerr << "Не удалось открыть файлы."
              << std::endl; // вывод сообщения об ошибке
    return 1;               // возвращаем код ошибки
  }

  int N;       // колличсетво адресов
  inFile >> N; // чтение колличества адресов из файла
  inFile.ignore(); // Пропускаем перевод строки после числа N

  std::vector<Address> addresses(N); // создаем вектор для хранения адресов

  for (int i = 0; i < N; ++i) { // цикл для чтоения адресов из файла
    std::getline(inFile, addresses[i].city);
    std::getline(inFile, addresses[i].street);
    std::getline(inFile, addresses[i].houseNumber);
    std::getline(inFile, addresses[i].apartmentNumber);
  }

  // Выводим количество адресов
  outFile << N << std::endl;

  // Выводим адреса в обратном порядке
  std::reverse(addresses.begin(), addresses.end()); // разворачиваем вектор
  for (const auto &address : addresses) {
    outFile << address.city << ", " << address.street << ",  "
            << address.houseNumber << ",  " << address.apartmentNumber
            << std::endl;
  }

  inFile.close();
  outFile.close();

  return 0;
}

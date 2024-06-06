//
//  HOMEWORK_2.cpp
//  HW3
//
//  Created by Anastasiya Charykova on 06.06.2024.
//

#include "HOMEWORK_2.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Address { // структура адресов
  std::string city;
  std::string street;
  std::string houseNumber;
  std::string apartmentNumber;
};

bool compareAddresses(const Address &a1, const Address &a2) { // сравнение адресов
  return a1.city < a2.city; // сортировка по городу
}

void bubbleSort(std::vector<Address> &arr) { // функция сортировки пузырьком
  int n = arr.size(); // колличество эллементов в массиве
  for (int i = 0; i < n - 1; i++) { // цикл для прохода по массиву
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j].city > arr[j + 1].city) { // сравнение городов
        Address temp = arr[j]; //
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  std::ifstream inFile("in.txt");
  std::ofstream outFile("out.txt");

  int n; // колличество адресов
  inFile >> n; // чтение адресов из файла

  std::vector<Address> addresses;

  for (int i = 0; i < n; i++) { // читаем адреса из файла
    Address address; // новый обьект адреса
    inFile >> address.city >> address.street >> address.houseNumber >>
        address.apartmentNumber; // чтение адреса из файла
    addresses.push_back(address); // добавление адреса в вектор
  }

  bubbleSort(addresses); // функция сортировки пузырьком

  outFile << addresses.size() << std::endl; // вывод колличества адресов

  for (const Address &address : addresses) {
    outFile << address.city << ", " << address.street << ", "
               << address.houseNumber << ", " << address.apartmentNumber
               << std::endl;
  }

  inFile.close();
  outFile.close();

  return 0;
}

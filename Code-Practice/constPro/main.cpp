#include <iostream>
#include "global.h"
int main() {
   struct Car {
      std::string brand;
      std::string model;
   };
   Car car = {"bm","x3"};
   std::cout << car << std::endl;
}

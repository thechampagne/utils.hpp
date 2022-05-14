#include <iostream>
#include "utils.hpp"

int main() {
  int* ptr = new int[2];
  ptr[0] = 55;
  ptr[1] = 23;
  int new_size = 3;
  try {
    ptr = utils::array_resize(ptr, 2, new_size);
  } 
  catch (utils::utils_exception& e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }
  ptr[2] = 72;
  for (int i = 0; i < new_size; i++) {
    std::cout << ptr[i] << std::endl;
  }

  return 0;
}
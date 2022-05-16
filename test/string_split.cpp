#include <iostream>
#include "utils.hpp"

int main() 
{
  std::string str = "Collection of utility for C++.";
  int length;
  
  char** arr = utils::string_split(str, " ", &length);
  
  for(int i = 0; i < length; i++)
  {
    std::cout << arr[i] << std::endl;
  }

  for(int i = 0; i < length; i++)
  {
    delete arr[i];
  }
  delete[] arr;
  
  return 0;
}

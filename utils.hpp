/*
 * Copyright (c) 2022 XXIV
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __CPP_UTILS_HPP__
#define __CPP_UTILS_HPP__

#include <exception>
#include <cstring>

namespace utils {

/**
 * utils Main exception
 */
struct utils_exception : public std::exception 
{
  const char* message;
  utils_exception(const char* message)
  {
      this->message = message;
  }
  const char* what() const throw()
  {
      return this->message;
  }
};


/**
 * Resize dynamic array
 *
 * Example:
 * * *
 * #include <iostream>
 * #include "utils.hpp"
 * 
 * int main() {
 *   int* ptr = new int[2];
 *   ptr[0] = 55;
 *   ptr[1] = 23;
 *   int new_size = 3;
 *   try {
 *     ptr = utils::array_resize(ptr, 2, new_size);
 *   } 
 *   catch (utils::utils_exception& e)
 *   {
 *     std::cout << e.what() << std::endl;
 *     return 1;
 *   }
 *   ptr[2] = 72;
 *   for (int i = 0; i < new_size; i++) {
 *     std::cout << ptr[i] << std::endl;
 *   }
 * 
 *   return 0;
 * }
 * * *
 *
 * @param ptr pointer to the allocated array
 * @param osize array old size
 * @param nsize array new size
 * @throws utils::utils_exception if something went wrong
 * @return dynamic array
 */
template <typename T>
T* array_resize(T* ptr, size_t osize, size_t nsize)
{
    
  T* new_ptr = new T[nsize];

  if (nsize <= osize)
  {
    throw utils_exception("invalid next size");
  }

  memcpy(new_ptr, ptr, osize * sizeof(T));
  
  return new_ptr;
}

}  // namespace utils

#endif  // __CPP_UTILS_HPP__
#ifndef ASSERT_HPP
#define ASSERT_HPP

#include "AssertError.hpp"

namespace stu {

void assert_eq(int a, int b);
void assert_greater(int a, int b);
void assert_lesser(int a, int b);

} // namespace stu

#endif // ASSERT_HPP
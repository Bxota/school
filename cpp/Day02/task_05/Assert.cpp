#include "Assert.hpp"

namespace stu {

void assert_eq(int a, int b) {
    if (a != b) {
        throw AssertError(a, b, "values are not equal");
    }
}

void assert_greater(int a, int b) {
    if (a <= b) {
        throw AssertError(a, b, "first value is not greater than second");
    }
}

void assert_lesser(int a, int b) {
    if (a >= b) {
        throw AssertError(a, b, "first value is not lesser than second");
    }
}

} // namespace stu
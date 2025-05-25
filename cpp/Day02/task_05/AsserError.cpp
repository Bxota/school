#include "AssertError.hpp"

namespace stu {

AssertError::AssertError(int left, int right, const std::string& msg)
    : lhs(left), rhs(right), message("Assertion error: " + msg + " (" + std::to_string(lhs) + " vs " + std::to_string(rhs) + ")") {}

const char* AssertError::what() const noexcept {
    return message.c_str();
}

} // namespace stu
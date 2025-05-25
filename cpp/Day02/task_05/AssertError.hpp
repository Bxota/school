#ifndef ASSERT_ERROR_HPP
#define ASSERT_ERROR_HPP

#include <exception>
#include <string>

namespace stu {

class AssertError : public std::exception {
private:
    const int lhs;
    const int rhs;
    std::string message;

public:
    AssertError(int left, int right, const std::string& msg);
    const char* what() const noexcept override;
};

} // namespace stu

#endif // ASSERT_ERROR_HPP
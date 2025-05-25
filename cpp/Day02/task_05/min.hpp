#ifndef MIN_HPP
#define MIN_HPP

template <typename T1, typename T2>
auto min(const T1& a, const T2& b) {
    return (a < b) ? a : b;
}

#endif // MIN_HPP
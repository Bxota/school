#ifndef MAX_HPP
#define MAX_HPP

// Fonction template pour retourner le plus grand des deux
template <typename T1, typename T2>
auto max(const T1& a, const T2& b) {
    return (a > b) ? a : b;
}

#endif // MAX_HPP
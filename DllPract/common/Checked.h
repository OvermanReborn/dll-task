#pragma once

#include <cerrno>
#include <limits>

// При переполнении возвращаем 0 и устанавливаем errno = ERANGE.
// Вызывающий код отличает ошибку от обычного нуля по errno.
inline int checked_int(long long value) noexcept {
    if (value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max()) {
        errno = ERANGE;
        return 0;
    }

    errno = 0;
    return static_cast<int>(value);
}

// Непустой массив с ненулевым указателем считается допустимым.
inline bool valid_array(const int* data, int size) noexcept {
    if (data == nullptr || size <= 0) {
        errno = EINVAL;
        return false;
    }

    errno = 0;
    return true;
}

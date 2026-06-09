#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include "../Date.h"

// Khai báo các hàm điều khiển tầng giao diện người dùng
void Display() noexcept;
void Bye() noexcept;
void ClearInputBuffer() noexcept;
void HandleInputError(Date& date);

#endif // CONSOLE_UTILS_H
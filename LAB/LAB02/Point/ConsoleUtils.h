#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include "Point.h"

// Gom toàn bộ các hàm giao diện Console vào đây
void Display() noexcept;
void Bye() noexcept;
void ClearInputBuffer() noexcept;
void HandleInputError(Point& point);

#endif // CONSOLE_UTILS_H
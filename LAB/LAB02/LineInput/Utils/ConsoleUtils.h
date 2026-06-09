#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include "../../Point/Point.h"
#include "../Line.h"

// Gom toàn bộ các hàm giao diện Console vào đây
void Display() noexcept;
void Bye() noexcept;
void ClearInputBuffer() noexcept;
void HandleInputError(Line& line);

#endif // CONSOLE_UTILS_H
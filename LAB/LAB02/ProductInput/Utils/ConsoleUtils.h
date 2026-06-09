#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include "../Product.h"

void Display() noexcept;
void Bye() noexcept;
void ClearInputBuffer() noexcept;
void HandleProductInputError(Product& product);

#endif // CONSOLE_UTILS_H
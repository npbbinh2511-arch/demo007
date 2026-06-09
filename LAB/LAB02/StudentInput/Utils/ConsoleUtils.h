#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include "../Student.h"

void Display() noexcept;
void Bye() noexcept;
void ClearInputBuffer() noexcept;
void HandleStudentInputError(Student& student);

#endif // CONSOLE_UTILS_H
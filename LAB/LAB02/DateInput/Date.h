#ifndef DATE_H
#define DATE_H

#include <iostream>

// Class giúp đảm bảo tính hợp lệ (Invariants) của dữ liệu ngày/tháng/năm,
// tránh việc người dùng vô tình gán các giá trị vô lý (ví dụ: ngày 32, tháng 13).
class Date {
private:
    int m_day;   // Ngày
    int m_month; // Tháng
    int m_year;  // Năm
    static bool isLeapYear(int year) noexcept {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    static int getDaysInMonth(int month, int year) noexcept {
        switch (month) {
            case 4: case 6: case 9: case 11: return 30;
            case 2: return isLeapYear(year) ? 29 : 28;
            default: return 31;
        }
    }

public:
    // Hàm tĩnh công khai để các tầng khác (như ConsoleUtils) cũng có thể dùng để kiểm tra
    static bool isValidDate(int day, int month, int year) noexcept {
        if (year <= 0) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > getDaysInMonth(month, year)) return false;
        return true;
    }
    // Khởi tạo mặc định (Default Constructor)
    Date() : m_day{1}, m_month{0}, m_year{0} {}
    
    // Khởi tạo có tham số
    Date(int day, int month, int year) : m_day{day}, m_month{month}, m_year{year} {}

    // Các hàm Getter (hứa không sửa đổi trạng thái bằng từ khóa const)
    int getDay() const noexcept  { return m_day; }
    int getMonth() const noexcept { return m_month; }
    int getYear() const noexcept { return m_year; }

    // Các hàm Setter để cập nhật dữ liệu một cách an toàn
    void setDay(int value) noexcept { m_day = value; }
    void setMonth(int value) noexcept { m_month = value; }
    void setYear(int value) noexcept { m_year = value; }

    // Nạp chồng toán tử luồng (Friend functions)
    friend std::istream& operator>>(std::istream& in, Date& date);
    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

#endif // DATE_H
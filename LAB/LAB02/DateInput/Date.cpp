#include "Date.h"

// Triển khai toán tử nhập luồng thô
std::istream& operator>>(std::istream& in, Date& date) {
    int tempDay, tempMonth, tempYear;
    
    // Nếu luồng đọc thành công 3 số nguyên
    if (in >> tempDay >> tempMonth >> tempYear) {
        // Kiểm tra điều kiện tiên quyết (Precondition)
        if (Date::isValidDate(tempDay, tempMonth, tempYear)) {
            date.m_day = tempDay;
            date.m_month = tempMonth;
            date.m_year = tempYear;
        } else {
            // Vi phạm Precondition -> Ép luồng vào trạng thái lỗi (failbit)
            in.setstate(std::ios::failbit);
        }
    }
    return in;
}

// Triển khai toán tử xuất luồng định dạng chuẩn DD/MM/YYYY
std::ostream& operator<<(std::ostream& out, const Date& date) {
    // Định dạng in ra màn hình đẹp mắt, rõ ràng
    out << (date.m_day < 10 ? "0" : "") << date.m_day << "/"
        << (date.m_month < 10 ? "0" : "") << date.m_month << "/"
        << date.m_year;
    return out;
}
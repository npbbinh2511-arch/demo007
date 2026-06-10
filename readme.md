## Thông tin cá nhân
MSSV: **25127020**
Tên: **Nguyễn Phi Bảo Bình**

## Line & Point

```mermaid
classDiagram
    class Point {
        - float m_x
        - float m_y
        + Point()
        + Point(float x, float y)
        + float getX() const
        + float getY() const
        + void setX(float value)
        + void setY(float value)
    }

    class Line {
        - Point _start
        - Point _end
        + Line()
        + Line(Point start, Point end)
        + void inputLine()
        + Point getStartPoint() const
        + Point getEndPoint() const
        + void setStartPoint(Point start)
        + void setEndPoint(Point end)
    }

    %% Các toán tử Friend độc lập bên ngoài hệ thống lớp
    class Global_Operators {
        + operator>>(istream& in, Point& point)
        + operator<<(ostream& out, const Point& point)
        + operator>>(istream& in, Line& x)
        + operator<<(ostream& os, Line x)
    }

    %% Mối quan hệ thành phần (Composition): Line chứa và quản lý vòng đời của 2 điểm Point
    Line *-- Point : _start
    Line *-- Point : _end
    %% Mối quan hệ sử dụng của các toán tử nhập xuất
    Global_Operators ..> Point : manipulates
    Global_Operators ..> Line : manipulates
```

## Sơ đồ lớp Date đầy đủ chi tiết

```mermaid
classDiagram
    class Date {
        - int m_day
        - int m_month
        - int m_year
        - isLeapYear(int year) bool$
        - getDaysInMonth(int month, int year) int$
        + Date()
        + Date(int day, int month, int year)
        + getDay() int const
        + getMonth() int const
        + getYear() int const
        + setDay(int value) void
        + setMonth(int value) void
        + setYear(int value) void
        + isValidDate(int day, int month, int year) bool$
    }

    %% Các toán tử Friend độc lập bên ngoài lớp
    class Global_Operators {
        + operator>>(istream& in, Date& date)
        + operator<<(ostream& out, const Date& date)
    }

    %% Mối quan hệ sử dụng dữ liệu
    Global_Operators ..> Date : manipulates
```

## Sơ đồ lớp Student và Date

```mermaid
classDiagram
    class Date {
        - int m_day
        - int m_month
        - int m_year
        + Date()
        + int getDay() const
        + int getMonth() const
        + int getYear() const
        + bool isValidDate(int d, int m, int y)$
    }

    class Student {
        - string m_id
        - string m_fullname
        - string m_address
        - string m_email
        - Date m_dob
        + Student()
        + string getId() const
        + string getFullname() const
        + string getAddress() const
        + string getEmail() const
        + Date getDOB() const
        + void setId(string id)
        + void setFullname(string name)
        + void setAddress(string addr)
        + void setEmail(string email)
        + void setDOB(Date dob)
        + int getCurrentYear()$
        + bool isValidDOB(Date dob)$
        + bool isValidStudent(string id, string name, Date dob)$
    }

    %% Các toán tử Friend độc lập bên ngoài hệ thống lớp
    class Global_Operators {
        + operator>>(istream& in, Student& student)
        + operator<<(ostream& out, const Student& student)
    }

    %% Mối quan hệ thành phần (Composition) giữa Student và Date
    Student *-- Date : m_dob
    %% Mối quan hệ sử dụng của các toán tử nhập xuất
    Global_Operators ..> Student : manipulates
```

## Sơ đồ lớp Product và Date

```mermaid
classDiagram
    class Date {
        - int m_day
        - int m_month
        - int m_year
        + Date()
        + int getDay() const
        + int getMonth() const
        + int getYear() const
        + bool isValidDate(int d, int m, int y)$
    }

    class Product {
        - string m_id
        - string m_name
        - float m_price
        - Date m_expiryDate
        + Product()
        + string getId() const
        + string getName() const
        + float getPrice() const
        + Date getExpiryDate() const
        + void setId(string id)
        + void setName(string name)
        + void setPrice(float price)
        + void setExpiryDate(Date expiry)
        + bool isValidProduct(string id, string name, float price, Date expiry)$
    }

    %% Các hàm bạn (Friend functions) tự do bên ngoài hệ thống lớp
    class Global_Operators {
        + operator>>(istream& in, Product& product)
        + operator<<(ostream& out, const Product& product)
    }

    %% Mối quan hệ thành phần (Composition) giữa Product và Date
    Product *-- Date : m_expiryDate
    %% Mối quan hệ sử dụng của các hàm Friend nhập xuất
    Global_Operators ..> Product : manipulates
```


## Hướng Dẫn Biên Dịch

**Point**
```Bash
g++ ./*.cpp -o main
```

**Line**
```Bash
g++ ./*.cpp ./Utils/*.cpp ../Point/Point.cpp -o main
```

**Date**
```Bash
g++ ./*.cpp ./Utils/*.cpp -o main
```

**Student**
```Bash
g++ ./*.cpp ./Utils/*.cpp ../DateInput/Date.cpp -o main
```

**Product**
```Bash
g++ ./*.cpp ./Utils/*.cpp ../DateInput/Date.cpp -o main
```
## Hướng Dẫn Chạy
```Bash
./main
```

ChatBox AI:
```Bash
https://gemini.google.com/share/d/1wGtyvBs46CWZGRb5coerUTdbYN5xwBdG?usp=sharing
```
```Bash
https://gemini.google.com/share/d/1QZ1HSFPsIAJIQGQJhOlC1EHZe6BBuFQm?usp=sharing
```
#include <iostream> 
#include <print> 
#include <string>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <regex>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class MoneyDisplay {
    private:
        int vnd = 0;
        int tryTimes = 0;
    public:
        double Exchange(int money) {
            return money*1.0 / 25500;
        }
        bool In_range(int money) {
            if (money <= 10000000 && money >= 1000000) return true;
            return false;
        }
        bool Is_digits(string str) {
            if(str.empty()) return false;
            for (char c: str) {
                if (!std::isdigit(c)) return false;
            }
            return true;
        }
        void Get_vnd() {
            while(tryTimes < 5 && vnd == 0) {
                string str;
                cout << "Nhap so tien ban muon doi: ";
                getline(cin, str);
                if(Is_digits(str) && In_range(std::stoi(str))) {
                    vnd = stoi(str);
                }
                else{
                    println("So tien nhap khong hop le, so lan nhap cua quy khach con {}\nVui long nhap lai!!!", 5-(++tryTimes));
                }
            }
        }
        void Display() {
            if(vnd == 0) {cerr << "Ban da het luot nhap!!"; return;}
            println("So tien sau khi doi cua ban la: {} vnd = ${:.2f}",vnd, Exchange(vnd));
        }
        void bye(){
            println("Vinh biet ban!");
        }
        void run()
        {
            println("Xin chao ban den voi dich vu doi tien! :>");
            Get_vnd();
            Display();
            bye();
        }
};

class RandomArrayIntegers{
    private:
        int _size = 0;
        int odd = 0;
        int even = 0;
        vector<int> arr;
    public:
        void Get_Size() {
            _size = rand()%10 +10;
        }
        void GenerateVector()
        {   
            Get_Size();
            arr.reserve(_size);
            for(int i = 0; i < _size; ++i) {
                arr.push_back(rand() % 100 + 1);
            }
        }
        void CountOddEvenNumbers() {
            for(int x : arr) {
                if(x%2 == 1) odd++;
                else even++;
            }
        }
        bool Is_prime(int const &x) const {
            if(x <= 1) return false;
            if(x <= 3) return true;
            if(x%2 == 0 || x%3 == 0) return false;
            int sqrtX = sqrt(x);
            for(int i = 5; i <= sqrtX; i+=6) {
                if (x % i == 0 || x % (i + 2) == 0) return false;
            }
            return true;
        }
        void PrimeNumbers() const {
            cout << "So nguyen to trong mang la: ";
            for(int x : arr) {
                if (Is_prime(x)) cout << x << " ";
            }
            cout << endl;
        }
        void PrintArray() const {
            cout << "Mang da tao la: ";
            for(int x : arr){
                cout << x << " ";
            }
            cout << endl;
        }
        void bye(){
            cout << "Chuong trinh da ket thuc!";
        }
        void Display() {
            srand(time(0));
            cout << "Chao mung ban da den voi may tao mang!!\nHay nhap phim 'enter' de chay chuong trinh.";
            string rong;
            getline(cin, rong);
            GenerateVector();
            PrintArray();
            PrimeNumbers();
            CountOddEvenNumbers();
            println("Mang co {} so chan va {} so le.", even, odd);
            bye();
        }
};

class FractionToDouble {
    private: 
        int mau = 1;
        int tu = 0;
        string str = "";
        double res = 0.00;
    public:
        void get_string() {
            getline(cin, str);
        }
        void get_tu_mau() {
            regex pattern(R"((\d+)/(\d+))");
            smatch match;
            bool found = regex_search(str, match, pattern);
            if (found) {
                tu = stoi(match[1]);
                mau = stoi(match[2]);
                res = (double)tu / mau;
            }
        }
        void display() {
            println("Xin chao ban den voi chuong trinh doi phan so thanh so thap phan :>");
            cout << "vui long nhap phan so: ";
            get_string();
            get_tu_mau();
            cout << '\n';
            println("so thap phan la: {:.2f}", res);
        }

};

class RaS {
    private:
        vector<int> _arr;
        int _size = 0;
        string filename = "";
    public:
        void Getfilename() {
            getline(cin, filename);
        }
        void Readfile() {
            ifstream fin(filename);
            if(!fin) {cout << "Loi roi may oi!\n"; return;}
            string buffer;
            while(getline(fin, buffer,','))
            {
                _arr.push_back(stoi(buffer));
                ++_size;
            }
            fin.close();
        }
        void Sort() {
            for(int i = 0; i < _size - 1; ++i){
                for(int j = i+1; j < _size; ++j)
                {
                    if(_arr[i] > _arr[j]){
                        int temp = _arr[i];
                        _arr[i] = _arr[j];
                        _arr[j] = temp;
                    }
                }
            }
        }
        void PrintAll(){
            for(int x : _arr){
                cout << x << " ";
            }
        }
        void run(){
            cout << "Vui long nhap ten file: ";
            Getfilename();
            Readfile();
            Sort();
            PrintAll();
            return;
        }
};

int main(){
    RaS oj1;
    oj1.run();
    return 0;
}
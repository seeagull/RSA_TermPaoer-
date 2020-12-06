#include <vector>
#include <string>
#include <ostream>
#include <iomanip>
#include <sstream>
 
class BigInteger 
{
    // основание системы счисления 1 000 000 000 
    static const int BASE = 1000000000;  

    // внутреннее представление числа
    std::vector<int> _digits;

    void _deleteLeadingZeros();
}

// удаляет лидирующие нули
void BigInteger::_deleteLeadingZeros()
{
    while (this->_digits.size() > 1 && this->_digits.back() == 0)
        {
            this->_digits.pop_back();
        } 
}

// создание числа из строки
BigInteger::BigInteger(std::string str)
{
    for (long long i = str.length(); i > 0; i -= 9)
    {
        if (i < 9) this->_digits.push_back(atoi(str.substr(0,i).c_str()));
        else this->_digits.push_back(atoi(str.substr(i - 9, 9).c_str()));
    }
    // удаление ведущих нулей
    this->_deleteLeadingZeros();
}

// выводит число 
std::ostream& operator <<(std::ostream& os, const BigInteger& BI)
{
    if (BI._digits.empty()) os << 0;
    else 
   {
        os << bi._digits.back();
        char oldFill = os.fill('0');
        for (long long i = static_cast<long long>(BI._digits.size()) - 2; i >= 0; --i)
        {
            os << std::setw(9) << BI._digits[i];
        }
        os.fill(oldFill);
    }
    return os;
}

    
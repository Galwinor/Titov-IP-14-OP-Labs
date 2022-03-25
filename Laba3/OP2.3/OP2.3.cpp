#include "OP2.3.h"
#include "Product.h"
using namespace std;

int main()
{
    vector<Product> Prod = input(); // Створення масиву об'єктів класу
    output(Prod); // Вивід інформації про продукти
    Out_Of_Date(Prod); // Визначення продуктів, в яких закінчився срок придатності
}
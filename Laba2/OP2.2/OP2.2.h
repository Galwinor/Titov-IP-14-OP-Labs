
struct Data {  
	int year;
	int mounth;
	int day;
};
struct AutoBase {
	char Name[15];
	Data Release; // Дата створення
	Data SaleRelease; // Дата продажу
};

using namespace std;

void input(char); // Ввід даних у файл
void output(string); // Вивід змісту файла
AutoBase Divide(AutoBase, string, bool); // Розділення дати у форматі string на змінні формату int
void CreateList(); // Створення списку з автомобылямы проданими за останный мысяць
string datta(); // Визначення поточної дати
void UseedAuto(); // Вивеедення інформації про афтомобілі, які були продані більше ніж через рік після створення
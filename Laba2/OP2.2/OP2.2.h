
struct Data {  
	int year;
	int mounth;
	int day;
};
struct AutoBase {
	char Name[15];
	Data Release; // ���� ���������
	Data SaleRelease; // ���� �������
};

using namespace std;

void input(char); // ��� ����� � ����
void output(string); // ���� ����� �����
AutoBase Divide(AutoBase, string, bool); // ��������� ���� � ������ string �� ���� ������� int
void CreateList(); // ��������� ������ � ������������ ��������� �� �������� ������
string datta(); // ���������� ������� ����
void UseedAuto(); // ���������� ���������� ��� ��������, �� ���� ������ ����� �� ����� �� ���� ���������
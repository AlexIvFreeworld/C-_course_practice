#include <direct.h>
#include <iostream>
#include <stdio.h>
#pragma warning(disable : 4996)
#define TEST

using namespace std;

//Переименовать существующую директорию
void RenameDirectory();
//Удалить существующую директорию
void RemoveDirectory();
//создать директорию
void CreateDirectory();

int main() {
#ifndef TEST
  //предлагаем выбрать пункт меню для выполнения
  cout << "Please, select preffer number...\n";
  //выбор пользователя
  char ch;
  do {
    //Переименовать
    cout << "\n1 - Rename\n";
    //Удалить
    cout << "2 - Remove\n";
    //Создать
    cout << "3 - Create\n";
    //Выход
    cout << "0 - Exit\n\n";
    cin >> ch;
    //анализируем и вызываем
    //соответствующую функцию
    switch (ch) {
    case '1':
      RenameDirectory();
      break;
    case '2':
      RemoveDirectory();
      break;
    case '3':
      CreateDirectory();
      break;
    }
  } while (ch != '0'); // Выход из программы
#else
	cout << "Create new directory my_dir...." << endl;
	CreateDirectory();
	cout << "Rename directory my_dir to my_dir_2...." << endl;
	RenameDirectory();
	cout << "Remove directory my_dir_2...." << endl;
	RemoveDirectory();
#endif

	cin.get();
	return 0;
}
//Переименовать существующую директорию
void RenameDirectory() {
  char oldName[50], newName[50];
#ifndef TEST
  //В одной переменной запомним
  //существующее имя (oldName),
  cout << "Enter old name:";
  cin >> oldName;
  //А в другой новое имя(newName)
  cout << "Enter new name:";
  cin >> newName;
  //Произведем переименование и проверку результата
#else
  strcpy(oldName, "my_dir");
  strcpy(newName, "my_dir_2");
#endif
  if (rename(oldName, newName) != 0)
    cout << "Error!\n Couldn't rename directory.\n\n";
  else
    cout << "Ok...\n\n";
}

//Удалить существующую директорию
void RemoveDirectory() {
  char Name[50];
#ifndef TEST
  //Получаем имя и путь к удаляемой директории
  cout << "Enter name:";
  cin >> Name;
#else
  strcpy(Name, "my_dir_2");
#endif
  //Удаляем директорию и проверяем результат
  if (_rmdir(Name) == -1)
    cout << "Error!\n Couldn't remove directory.\n";
  else
    cout << "Ok...\n";
}

//Создать директорию
void CreateDirectory() {
  char Name[50];
  //Получаем имя и путь к создаваемой директории
#ifndef TEST
  cout << "Enter name:";
  cin >> Name;
#else
  strcpy(Name, "my_dir");
#endif

  //Создаем директорию и проверяем результат
  if (_mkdir(Name) == -1)
    cout << "Error!\n Couldn't create directory.\n";
  else
    cout << "Ok...\n";
}

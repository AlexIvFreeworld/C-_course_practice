//Здесь находятся функции переименования и удаления
#include <stdio.h>
//Здесь находятся функции для поиска файлов
#include <iostream>
#include <string.h>
#include <sys/io.h>
using namespace std;

//Переименовать существующий файл
void RenameFile();
//Удалить существующий файл
void RemoveFile();
//Поиск файлов в каталоге
// void Dir();

int main() {
  //предлагаем выбрать пункт меню для выполнения
  cout << "Please, select preffer number...\n";
  //выбор пользователя
  char ch;
  do {
    cout << "\n1 - Rename\n"; //Переименовать
    cout << "2 - Remove\n";   //Удалить
    cout << "3 - View some folder\n"; //Просмотреть некоторую папку(каталог)
    cout << "0 - Exit\n\n"; //Выход
    cin >> ch;
    //анализируем и вызываем соответствующую функцию
    switch (ch) {
    case '1':
      RenameFile();
      break;
    case '2':
      RemoveFile();
      break;
    case '3':
      // Dir();
      break;
    }
  } while (ch != '0'); //Выход из программы
}

//Переименовать существующий файл
void RenameFile() {
  char oldName[50], newName[50];
  //В одной переменной запомним существующее имя
  //(oldName),
  cout << "enter old name:";
  cin >> oldName;
  //А в другой новое имя(newName)
  cout << "enter new name:";
  cin >> newName;
  //Произведем переименование и проверку результата
  if (rename(oldName, newName) != 0)
    cerr << "error: Could not rename file. Check old and new filename...\n";
  else
    cout << "Ok...\n";
}

//Удалить существующий файл
void RemoveFile() {
  char Name[50];
  //Получаем имя и путь к удаляемому файлу
  cout << "enter name:";
  cin >> Name;

  //Удаляем файл и проверяем результат
  if (remove(Name) != 0)
    cout << "error: Could not remove file. Check filename...\n";
  else
    cout << "Ok...\n";
}

//Поиск файлов в каталоге
/*void Dir() {
  //Запросим ПУТЬ (например, папка Temp на диске C,
  // запишется таким вот образом: c:\temp\)
  char path[70];
  cout << "\nEnter full path (for example, C:\\):";
  cin >> path;
  //Запросим маску файлов
  char mask[15];
  cout << "\nEnter mask (for example, *.* or *.txt):";
  cin >> mask;
  //Соединив две строки, мы получим результат
  // т.е. что хочет найти пользователь и где
  strcat(path, mask);
  //Объявление указателя fileinfo на структуру _finddata_t
  //и создание динамического объекта структуры _finddata_t
  _finddata_t *fileinfo = new _finddata_t;
  //Начинаем поиск
  long done = _findfirst(path, fileinfo);
  //если done будет равняться -1,
  //то поиск вести бесмысленно
  int MayWeWork = done;
  //Счетчик, содержит информацию о количестве
  //найденых файлов.
  int count = 0;
  while (MayWeWork != -1) {
    count++;
    //Распечатали имя найденного файла
    cout << fileinfo->name << "\n\n";
    //Пытаемся найти следующий файл из группы
    MayWeWork = _findnext(done, fileinfo);
  }
  //Вывод сообщения о количестве найденных файлов.
  cout << "\nInformation: was found " << count;
  cout << " file(s) in folder..." << path << "\n\n";

  //Очистка памяти
  _findclose(done);
  delete fileinfo;
} */

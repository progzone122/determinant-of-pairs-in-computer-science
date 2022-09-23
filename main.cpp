#include <iostream>
#include <time.h> //Дата и время
#include <windows.h> //Для установки кодировки

using namespace std;

auto getDate(){ //Функция определения сегодняшней даты
    time_t now = time(0);
    tm* tm = localtime(&now);
    int index = tm->tm_mday % 2; //Определям числитель или знаменатель
    static int date[] = {
        1900 + tm->tm_year, //Текущий год
        tm->tm_mon + 1, //Текущий месяц
        tm->tm_mday, //Текущий день
        index
    };
    return date;
}
string getWeekDay(int d, int m, int y){ //Функция определения дня недели
    int day_number = (d + m + y + (y / 4) ) % 7; //Формула для вычесления дня недели
    string days[] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суботта", "Воскресенье" };
    return days[day_number];
}

int main(){
    SetConsoleCP(65001); //Убираем кракозябры в консоли виндовс (устанавливаем кодировку)
    SetConsoleOutputCP(65001); //Убираем кракозябры в консоли виндовс (устанавливаем кодировку)
    // cout << getDate()[0];
    int group;
    const string weekDay = getWeekDay(getDate()[2], getDate()[1], getDate()[0]);
    cout << "Введите свою группу (1 / 2): ";
    cin >> group;
    switch(group){
        case 1:
            if(weekDay == "Четверг"){
                cout << "Сегодня пара информатики на 1 паре";
            }else if(weekDay == "Вторник"){
                cout << "Сегодня пара информатики на 2 паре";
            }else{
                cout << "Сегодня нет пары информатики";
            }
            break;
        case 2:
            if(weekDay == "Четверг"){

            }else if(weekDay == "Вторник"){
                if(getDate()[3] == 0){
                    cout << "Сегодня пара информатики на 2 паре";
                }else{
                    cout << "Сегодня нет пары информатики";
                }
            }else if(weekDay == "Пятница"){
                if(getDate()[3] == 1){
                    cout << "Сегодня пара информатики на 5 паре";
                }
            }else{
                cout << "Сегодня нет пары информатики";
            }
            break;
        default:
            cout << "[!] Неизвестная группа!\n";
            main();
            break;
    }

    return 0;
}

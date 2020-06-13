МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 6<br/> по дисциплине "Программирование"
<br/>

студента 1 курса группы ПИ-б-о 191(2)
Емельяненко Леонида Алексеевича
направления подготовки 09.03.04 "Программная инженерия"
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2019

#### Цель: Закрепить навыки разработки многофайловыx приложений. Изучить способы работы с API web-сервиса. Изучить процесс сериализации/десериализации данных.

API ключ, полученный с сервиса *openweathermap.org*: : 0d1c0fd8e5622110ab35894fd1d23988

Напишем программу для выполнения поставленной задачи:

```cpp
#include <iostream>
#include <httplib/httplib.h>
#include <Windows.h>
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
using namespace httplib;
using json = nlohmann::json;

struct info {
    string data;
    vector<json> icon;
    vector<string> temp;
};

string replace(string doc, string before, string after) {
    int index;
    if (after[0] == '\"') {
        after = after.substr(1, size(after)-2);
    }
    index = doc.find(before);
    doc.replace(index, size(before), after);
    return doc;
}
void gen_response(const httplib::Request& req, httplib::Response& red) {
    string URL = "api.openweathermap.org";
    vector<info> days;
    string line;
    string data;
    string city;
    string cur_data;
    bool have;
    httplib::Client cli(URL);
    auto res = cli.Get("/data/2.5/forecast?q=Simferopol&APPID=0d1c0fd8e5622110ab35894fd1d23988&units=metric");
    if (res && res->status == 200) {
        json j = json::parse(res->body);

        city = j["city"]["name"].dump();
        std::ifstream in("informer_template.html");
        if (in.is_open())
        {
            while (getline(in, line))
            {
                data += line + "\r";
            }
        }
        data = replace(data, "{city.name}", city);
        for (int i = 0; i < 40; i++) {
            have = false;
            cur_data = j["list"][i]["dt_txt"].dump().substr(1, 10);
            for (int k = 0; k < size(days); k++) {
                if (cur_data == days[k].data) {
                    days[k].icon.push_back(j["list"][i]["weather"][0]["icon"].dump());
                    days[k].temp.push_back(j["list"][i]["main"]["temp"].dump());
                    have = true;
                    break;
                }
            }
            if (!have) {
                days.push_back(info());
                days[days.size() - 1].data = cur_data;
                days[days.size() - 1].icon.push_back(j["list"][i]["weather"][0]["icon"].dump());
                days[days.size() - 1].temp.push_back(j["list"][i]["main"]["temp"].dump());
            }

        }

        for (int b = 0; b < 5; b++) {
            data = replace(data, "{list.dt}", days[b].data);
            data = replace(data, "{list.weather.icon}", days[b].icon[0]);
            data = replace(data, "{list.main.temp}", days[b].temp[0]);
        }
    }
    ofstream out;
    out.open("informer_template_result.html");
    if (out.is_open()) {
        out << data << endl;
    }
    red.set_content(data, "text/html");
}

int main(void) {
    Server svr;
    svr.Get("/", gen_response);
    svr.listen("localhost", 3000);
    
}
```
В итоге получаем следующий результат:

![](https://github.com/Leonid0208/CPP/blob/master/%D0%9B%D0%B0%D0%B1%D0%BE%D1%80%D0%B0%D1%82%D0%BE%D1%80%D0%BD%D1%8B%D0%B5%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%8B/%D0%9B%D0%B0%D0%B1%D0%BE%D1%80%D0%B0%D1%82%D0%BE%D1%80%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0%20%E2%84%966/img/Screen.png)
Рис.1 Результат работы


#### Вывод: поработал с форматом json в С++, попровал библиотеку httplib.

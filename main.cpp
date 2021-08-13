#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>
#include "vec2.h"
#include "field.h"
#include "unit.h"

//программа получает на вход имя файла с данными о юнитах, имя файла, в который следует записать информацию,
// имя файла в который будут нарисованы юниты (формат .ppm)
int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "не хватает данных";
        exit(1);
    }

    std::ifstream fin(argv[1]);
//    std::ifstream fin("test.txt");
    if (!fin.is_open()) {
        std::cout << "1 Файл не может быть открыт!\n";
        exit(1);
    }
    std::vector<unit> units;
    std::string line;
    getline(fin, line);

    std::regex rx(R"(([+-]?[[:digit:]]+(?:\.[[:digit:]]+)?))"); // шаблон чисел в тексте
    std::smatch m;
    regex_search(line, m, rx);
    double deg = strtod(m[1].str().c_str(), nullptr);
    line = m.suffix().str();
    regex_search(line, m, rx);
    double distance = strtod(m[1].str().c_str(), nullptr);

    while(getline(fin, line)) {
        regex_search(line, m, rx);
        int i =  strtod(m[1].str().c_str(), nullptr); // номер юнита
        line = m.suffix().str();

        regex_search(line, m, rx);
        int px = strtod(m[1].str().c_str(), nullptr);
        line = m.suffix().str();

        regex_search(line, m, rx);
        int py = strtod(m[1].str().c_str(), nullptr);
        line = m.suffix().str();

        regex_search(line, m, rx);
        double dx = strtod(m[1].str().c_str(), nullptr);
        line = m.suffix().str();

        regex_search(line, m, rx);
        double dy = strtod(m[1].str().c_str(), nullptr);
        units.emplace_back(unit(point2(px,py), vector2(dx, dy)));
    }

    fin.close();

    field f(units, units.size(), deg, distance);
    std::vector<size_t> amount = f.NumUnitsView();

    std::ofstream fout(argv[2]);
//    std::ofstream fout("res.txt");
    if (!fout.is_open()) {
        std::cout << "2 Файл не может быть открыт!\n";
        exit(1);
    }
    for (size_t i = 0; i < amount.size(); ++i) {
        fout << "Юнит" << i + 1 << ": видит " << amount[i] << "\n";
    }
    fout.close();

    std::ofstream iout(argv[3]);
//    std::ofstream iout("image.ppm");
    f.DrawUnits(iout);
    iout.close();
    return 0;
}

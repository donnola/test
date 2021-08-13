#include <thread>
#include <cstring>
#include <fstream>
#include "field.h"
#include "vec2.h"


void field::CheckVision(std::vector<size_t>& amount, size_t i,  size_t j) const {
    double m = MagnitudeSq(units[i].position - units[j].position);
    if (m <= sqDistance) {
        double c = CosBetweenVec(units[i].viewDir, units[j].position - units[i].position);
        if (c >= cosView) {
            amount[i] += 1;
        }
        c = CosBetweenVec(units[j].viewDir, units[i].position - units[j].position);
        if (c >= cosView) {
            amount[j] += 1;
        }
    }
}

std::vector<size_t> field::NumUnitsView() {
    size_t thread_num = std::thread::hardware_concurrency();
    size_t units_num = units.size();
    std::vector<size_t> amount(units_num, 0);
    std::vector<std::thread> threads;


//    for(int i = 0; i < thread_num; ++i) {
//        std::thread thr(&field::CheckVision, amount, i_start, 1);
//        i_start += 1;
//        threads.emplace_back(std::move(thr));
//    }
//    for(auto& thr : threads) {
//        thr.join();
//    }
//    size_t t = 0;
//    for (size_t i = 0; i < units_num - 1; ++i ) {
//        for (size_t j = i + 1; j < units_num; ++j) {
//
//        }
//    }


    for (size_t i = 0; i < units_num - 1; ++i ) {
        for (size_t j = i + 1; j < units_num; ++j) {
//            std::thread thr(&field::CheckVision, amount, i, j);
            double m = MagnitudeSq(units[i].position - units[j].position);
            if (m <= sqDistance) {
                double c = CosBetweenVec(units[i].viewDir, units[j].position - units[i].position);
                if (c >= cosView) {
                    amount[i] += 1;
                }
                c = CosBetweenVec(units[j].viewDir, units[i].position - units[j].position);
                if (c >= cosView) {
                    amount[j] += 1;
                }
            }
        }
    }
    return amount;
}

void field::DrawUnits(std::ofstream& iout) {
    point2 center(SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2);
    for (unit u : units) {
        buffer[int(center.x + u.position.x)][int(center.y + u.position.y)] = true;
    }
    iout << "P3\n" << SCREEN_WIDTH << ' ' << SCREEN_HEIGHT << "\n255\n";
    for (int i = 0; i < SCREEN_HEIGHT; ++i)  {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            if (buffer[i][j]) {
                iout << 255 << ' ' << 0 << ' ' << 0 << '\n';
            }
            else {
                iout << 255 << ' ' << 255 << ' ' << 255 << '\n';
            }
        }
    }
}


#include <thread>
#include "field.h"
#include "vec2.h"

std::vector<size_t> field::NumUnitsView() {
    size_t thread_num = std::thread::hardware_concurrency();
    size_t units_num = units.size();
    std::vector<size_t> amount(units_num, 0);
    for (size_t i = 0; i < units_num - 1; ++i ) {
        for (size_t j = i + 1; j < units_num; ++j) {
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

void field::DrawUnits() {

}

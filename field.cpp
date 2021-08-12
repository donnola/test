
#include "field.h"
#include "vec2.h"

std::vector<size_t> field::NumUnitsView() {

    size_t units_num = units.size();
    std::vector<size_t> amount(units_num, 0);
    for (size_t i = 0; i < units_num; ++i ) {
        for (size_t j = 0; j < units_num; ++j) {
            if (i != j && state[i][j] == 0) {
                double m = MagnitudeSq(units[i].position - units[j].position);
                if (m <= sqDistance) {
                    state[i][j] = 1;
                    state[j][i] = 1;
                }
                else {
                    state[i][j] = 2;
                    state[j][i] = 2;
                }
            }
            if (i != j && state[i][j] == 1) {
                double c = CosBetweenVec(units[i].viewDir, units[j].position - units[i].position);
                if (c >= cosView) {
                    amount[i] += 1;
                }
            }
        }
    }
    return amount;
}

void field::DrawUnits() {

}

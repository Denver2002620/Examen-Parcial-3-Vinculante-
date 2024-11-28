#include "ejercicio.h"

int main() {
    std::vector<Task> tasks = {
        {"A", 20, {}},
        {"B", 5, {}},
        {"C", 40, {"B"}},
        {"D", 10, {"A"}},
        {"E", 5, {"A", "D"}},
        {"F", 10, {"D"}},
        {"G", 20, {"C"}},
        {"H", 25, {"G"}},
        {"I", 35, {}},
        {"J", 25, {}},
        {"K", 15, {}},
        {"L", 5, {"K"}},
        {"M", 25, {"H"}}
    };

    const int max_time = 100;
    calculateSchedule(tasks, max_time);

    return 0;
}
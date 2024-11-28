#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <string>
#include <vector>

struct Task {
    std::string name;
    int duration;
    std::vector<std::string> dependencies;
};

bool calculateSchedule(const std::vector<Task>& tasks, int max_time);

#endif

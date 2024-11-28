#include "ejercicio.h"
#include <iostream>
#include <queue>
#include <unordered_map>

bool calculateSchedule(const std::vector<Task>& tasks, int max_time) {
    std::unordered_map<std::string, int> indegree;
    std::unordered_map<std::string, int> taskDuration;
    std::unordered_map<std::string, std::vector<std::string>> adjList;

    for (const auto& task : tasks) {
        indegree[task.name] = 0;
        taskDuration[task.name] = task.duration;
        adjList[task.name] = {};
    }

    for (const auto& task : tasks) {
        for (const auto& dep : task.dependencies) {
            adjList[dep].push_back(task.name);
            indegree[task.name]++;
        }
    }

    std::queue<std::string> readyTasks;
    std::vector<std::string> executionOrder;
    int totalTime = 0;

    for (const auto& task : tasks) {
        if (indegree[task.name] == 0) {
            readyTasks.push(task.name);
        }
    }

    while (!readyTasks.empty()) {
        std::string currentTask = readyTasks.front();
        readyTasks.pop();
        executionOrder.push_back(currentTask);
        totalTime += taskDuration[currentTask];

        for (auto& successor : adjList[currentTask]) {
            indegree[successor]--;
            if (indegree[successor] == 0) {
                readyTasks.push(successor);
            }
        }
    }

    if (executionOrder.size() == tasks.size() && totalTime <= max_time) {
        std::cout << "Es posible completar las tareas en " << totalTime << " minutos.\n";
        std::cout << "Orden de ejecución óptimo: ";
        for (const auto& task : executionOrder) {
            std::cout << task << " ";
        }
        std::cout << std::endl;
        return true;
    } else
    {
        std::cout << "No es posible completar todas las tareas en el tiempo dado.\n";
        return false;
    }
    return 0;
}
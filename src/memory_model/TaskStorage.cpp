//
// Created by denis on 12.07.20.
//

#include "TaskStorage.h"

std::unique_ptr<Task> TaskStorage::createTask(const std::string &name, Task::Priority priority, const std::string &label, time_t date) {
    return std::make_unique<Task>(Task {name, priority, label, date});
}
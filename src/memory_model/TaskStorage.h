//
// Created by denis on 12.07.20.
//

#ifndef EVAL_TASKSTORAGE_H
#define EVAL_TASKSTORAGE_H
#include "Task.h"

class TaskStorage {

public:
    std::unique_ptr<Task> createTask(const std::string& name, Task::Priority priority, const std::string& label, time_t date);

};


#endif //EVAL_TASKSTORAGE_H

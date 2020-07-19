#include <iostream>

#include "memory_model/TaskService.h"
#include "memory_model/TaskID.h"
#include "task_io/task_io.h"

int main() {
    TaskIDFactory fc;
    TaskID t = fc.generateID();
    TaskService service;
    TaskID id = service.addTask("T1", Task::Priority::NONE, "tag", 2020);
    TaskID id2 = service.addSubTask(id, "T2", Task::Priority::SECOND, "tag2", 2021);
    TaskID id3 = service.addSubTask(id2, "T3", Task::Priority::NONE, "tag3", 2022);
    service.inspectRoot();
    service.popTask(id2);
    service.inspectRoot();
    TaskID id4 = service.addTask("T5", Task::Priority::FIRST, "tag4", 2020);
    service.inspectRoot();
    TaskID id5 = service.addSubTask(id, "T6", Task::Priority::THIRD, "tag5", 2021);
    service.inspectRoot();
    service.popTask(id5);
    service.inspectRoot();
    TaskID id6 = service.addSubTask(id4, "T7", Task::Priority::NONE, "tag6", 2022);
    service.inspectRoot();
    service.popTask(id);
    service.inspectRoot();
    TaskID id7 = service.addSubTask(id4, "T8", Task::Priority::NONE, "tag7", 2022);
    service.inspectRoot();
    auto tsk = service.getAllTasks();
    for (auto ts : tsk) {
        std::cout << ts;
    }
    std::cout << "after delete\n";
    return 0;
}

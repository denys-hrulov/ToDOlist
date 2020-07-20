//
// Created by denis on 20.07.20.
//

#ifndef TODOLIST_TASKIDCONVERTER_H
#define TODOLIST_TASKIDCONVERTER_H

#include "TaskController.h"
#include "UserTaskID.h"

class TaskIDConverter {
public:
    explicit TaskIDConverter(const TaskController& ref_tree) : ref_tree_(ref_tree) {}

public:
    TaskID getTaskID(UserTaskID user_id);
    UserTaskID getUserTaskID(TaskID system_id);

private:

    const TaskController& ref_tree_;
};


#endif //TODOLIST_TASKIDCONVERTER_H
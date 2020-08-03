//
// Created by denis on 13.07.20.
//

#ifndef TODOLIST_TASKDTO_H
#define TODOLIST_TASKDTO_H

#include "memory_model/Task.h"
#include "memory"
#include "memory_model/TaskID.h"

class TaskDTO {

public:
    TaskDTO(const Task&);
    TaskDTO(TaskID, const Task&);
    TaskDTO(TaskID, const Task&, bool complete);
    TaskDTO(TaskID, const std::string& name, Task::Priority, const std::string& label, time_t);
    TaskDTO(        const std::string& name, Task::Priority, const std::string& label, time_t);
    TaskDTO(TaskID, const std::string& name, Task::Priority, const std::string& label, time_t, bool);
    TaskDTO(const TaskDTO&) = default;

public:
    TaskID                  getId() const ;
    std::string             getName() const ;
    Task::Priority          getPriority() const ;
    std::string             getLabel() const ;
    time_t                  getDate() const ;
    bool                    isComplete() const ;


private:
    TaskID id_;
    std::string name_;
    Task::Priority priority_;
    std::string label_;
    time_t date_;
    bool complete_;
};


#endif //TODOLIST_TASKDTO_H

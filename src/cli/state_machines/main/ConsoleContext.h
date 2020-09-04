//
// Created by denis on 18.08.20.
//

#ifndef TODOLIST_CONSOLECONTEXT_H
#define TODOLIST_CONSOLECONTEXT_H


#include "core/api/TaskServiceInterface.h"
#include "cli/ConsoleIOInterface.h"
class State;

typedef uint32_t TaskNumber;

class ConsoleContext {

public:
    explicit
    ConsoleContext( std::unique_ptr<TaskServiceInterface>,
                    std::unique_ptr<ConsoleIOInterface>);

public:
    TaskServiceInterface&                   getTaskService();
    ConsoleIOInterface &                    getIO();
    std::map<TaskNumber, TaskID>&           getTaskTable();
    std::map<TaskID, TaskNumber>&           getIDTable();

public:
    void                                    fillTaskBuffer(const TaskDTO&);
    std::optional<TaskDTO>                  getTaskBuffer();
    std::optional<TaskID>                   getBufferedId() const;

private:


    std::map<TaskNumber, TaskID>            task_table_;
    std::map<TaskID, TaskNumber>            id_table_;
    std::unique_ptr<ConsoleIOInterface>     io_;

private:
    std::optional<TaskID>                   id_buffer_;
    std::optional<TaskDTO>                  task_buffer_;
    std::unique_ptr<TaskServiceInterface>   service_;

};



#endif //TODOLIST_CONSOLECONTEXT_H

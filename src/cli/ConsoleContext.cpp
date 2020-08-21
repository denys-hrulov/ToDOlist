//
// Created by denis on 18.08.20.
//

#include "ConsoleContext.h"
#include "states/State.h"

ConsoleContext::ConsoleContext(
        std::unique_ptr<TaskServiceInterface> service)
        :
        service_(std::move(service))
{}


TaskBuffer &ConsoleContext::getTaskBuffer() {
    return task_buffer_;
}

TaskServiceInterface &ConsoleContext::getTaskService() {
    return *service_;
}

ConsoleIO &ConsoleContext::getIO() {
    return console_;
}

std::map<TaskNumber, TaskID> &ConsoleContext::getTaskTable() {
    return task_table_;
}

std::map<TaskID, TaskNumber> &ConsoleContext::getIDTable() {
    return id_table_;
}

std::optional<TaskID> ConsoleContext::getBufferedId() const {
    return id_buffer_;
}








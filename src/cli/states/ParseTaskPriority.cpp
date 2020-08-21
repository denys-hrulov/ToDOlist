//
// Created by denis on 19.08.20.
//

#include "ParseTaskPriority.h"
#include "ParseTaskLabel.h"
#include "StartState.h"
#include "cli/ConsoleContext.h"

ParseTaskPriority::ParseTaskPriority(const std::shared_ptr<State>& next_state) :
        ParseTask(next_state)
{}

void ParseTaskPriority::print(ConsoleContext& context) {
    context.getIO().log("Task priority:");
}

std::shared_ptr<State> ParseTaskPriority::execute(ConsoleContext& context) {
    std::string input = context.getIO().read();
    if (input.empty()) {
        context.getIO().log("Task priority must not be empty");
        return std::make_shared<StartState>(nullptr);
    }
    for (auto &symbol : input) {
        symbol = std::tolower(symbol);
    }
           if (input == "first" || input == "1") {
               context.getTaskBuffer().priority_ = TaskPriority::FIRST;
    } else if (input == "second" || input == "2") {
               context.getTaskBuffer().priority_ = TaskPriority::SECOND;
    } else if (input == "third" || input == "3") {
               context.getTaskBuffer().priority_ = TaskPriority::THIRD;
    } else if (input == "none" || input == "0") {
               context.getTaskBuffer().priority_ = TaskPriority::NONE;
    } else {
               context.getIO().log("Incorrect priority!");
               context.getIO().log("Possible : ");
               context.getIO().log("first    (1)");
               context.getIO().log("second   (2)");
               context.getIO().log("third    (3)");
               context.getIO().log("none     (0)");
               return std::make_shared<StartState>(nullptr);
    }
    return next_state_;
}

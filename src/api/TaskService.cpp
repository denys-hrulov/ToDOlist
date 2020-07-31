//
// Created by denis on 10.07.20.
//

#include "TaskService.h"


TaskDTO getDTO(const std::weak_ptr<TaskNode>& node) {
    auto shared_node = node.lock();
    TaskID id_task = shared_node->getId();
    return TaskDTO(id_task, shared_node->getTask());
}

std::vector<TaskDTO> convertAll(const std::vector<std::weak_ptr<TaskNode>>& all) {
    std::vector<TaskDTO> user_result_set;
    std::transform(all.begin(), all.end(),
                   std::back_inserter(user_result_set),
                   getDTO
    );
    return user_result_set;
}

/**********************************************************************/

void TaskService::addToViews(const std::shared_ptr<TaskNode>& node) {
    nodes_[node->getId()] = node;
    by_time_->addToView(node);
    by_label_->addToView(node);
}

void TaskService::eraseAllReferences(TaskID id) {
    auto parent = nodes_[id]->getParent();
    if (parent) {
        parent->eraseSubtask(id);
    }
    nodes_.erase(id);
    by_time_->removeFromView(id);
    by_label_->removeFromView(id);
}

TaskCreationResult TaskService::addTask(const TaskDTO &task_data) {
    Task task = task_creator_->createTask(task_data);
    TaskID generated_id = id_generator_->generateID();
    auto created_node = std::make_shared<TaskNode>(generated_id, task);
    // set links to new node
    addToViews(created_node);
    return TaskCreationResult::success(generated_id);
}

TaskCreationResult TaskService::addSubTask(TaskID parent, const TaskDTO &task_data) {
    if (nodes_.count(parent) == 0) {
        return TaskCreationResult::taskNotFound();
    }
    // create Node
    auto result = addTask(task_data);
    TaskID generated_id = result.getCreatedTaskID().value();
    // tie new node with parent
    auto created_node = nodes_[generated_id];
    auto parent_node = nodes_[parent];
    parent_node->addSubtask(created_node);
    created_node->setParent(parent_node);

    return TaskCreationResult::success(generated_id);
}

void TaskService::deleteTask(TaskID id) {
    for (TaskID subtask : nodes_[id]->getSubtasks()) {
        deleteTask(subtask);
    }
    eraseAllReferences(id);
}

void TaskService::postponeTask(TaskID id, time_t date_postpone) {
    auto old_node = nodes_[id];
    auto new_node =
            std::make_shared<TaskNode>(
                    id,
                    task_creator_->createPostponedTask(old_node->getTask(), date_postpone)
            );
    for (auto subnode : nodes_[id]->getSubNodes()) {
        // link children with new node
        new_node->addSubtask(subnode);
        subnode->setParent(new_node);
    }
    eraseAllReferences(id);
    addToViews(new_node);
}

std::vector<TaskDTO> TaskService::getAllTasks() {
    auto result_set = by_time_->getAll(std::numeric_limits<time_t>::max());
    return convertAll(result_set);
}

std::vector<TaskDTO> TaskService::getAllWithLabel(const std::string &label) {
    auto result_set = by_label_->getAll(label);
    return convertAll(result_set);
}


TaskDTO TaskService::getTaskByID(TaskID id) {
    return TaskDTO(id, nodes_[id]->getTask());
}


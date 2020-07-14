//
// Created by denis on 13.07.20.
//

#ifndef TODOLIST_TASKCONTROLLER_H
#define TODOLIST_TASKCONTROLLER_H

#include "TaskNode.h"

class TaskController {

public:

    std::weak_ptr<TaskNode>     createChild(uint id_parent, std::unique_ptr<Task> tptr);
    std::weak_ptr<TaskNode>     createSingleNode(std::unique_ptr<Task> tptr);
    std::vector<uint>           getAllSubtasks(uint id_parent);
    void                        eraseNode(uint id_erase);

private:
    uint getNextAvailableId();

private:
    std::shared_ptr<TaskNode> createNode(std::unique_ptr<Task> tptr);

    // stateful functions that require careful usage
    void __find_all_children(const TaskNode& tnode, std::vector<uint>& buf);
    void __bind_parent(std::list<std::shared_ptr<TaskNode>>*, const std::shared_ptr<TaskNode>&);
    void __erase_node_references(uint node_id);
    void __remove_from_tree(uint);

    std::list<std::shared_ptr<TaskNode>> task_nodes_;
    std::map<uint, std::shared_ptr<TaskNode>> id_to_node_;
    // map of ids' corresponding to parent node list and place of node in the list with given id
    std::unordered_map<
                    uint,
                    std::pair<
                            std::list<std::shared_ptr<TaskNode>>*,
                            std::list<std::shared_ptr<TaskNode>>::iterator
                             >
                    >
                    node_places_;
};


#endif //TODOLIST_TASKCONTROLLER_H

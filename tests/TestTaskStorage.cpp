//
// Created by denis on 14.07.20.
//

#include <gtest/gtest.h>
#include "memory_model/TaskStorage.h"
#include "memory_model/TaskStorage.cpp"

class TaskStorageTest : public ::testing::Test {

};

TEST_F(TaskStorageTest, ptrIsValid) {
    TaskStorage ts;
    auto ptask = ts.createTask("name", Task::Priority::NONE, "lbl", 2020);
    ASSERT_TRUE(ptask);
    EXPECT_EQ(ptask->name, "name");
    EXPECT_EQ(ptask->priority, Task::Priority::NONE);
    EXPECT_EQ(ptask->label, "lbl");
    EXPECT_EQ(ptask->date, 2020);
}
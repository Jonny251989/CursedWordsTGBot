#pragma once

#include <gtest/gtest.h>

#include "queue.hpp"

class QueueTest : public ::testing::Test{

protected:
    void SetUp() override;
    void TearDown() override;
    Queue<int> queue;
};


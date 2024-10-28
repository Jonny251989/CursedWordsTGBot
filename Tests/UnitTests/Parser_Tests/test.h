#ifndef TEST_H
#define TEST_H

#include <gtest/gtest.h>
#include <optional>

#include "parser.hpp"

class ParserTest : public ::testing::Test{

protected:
    void SetUp() override;

    void TearDown() override;
	
};


#endif
#include <gtest/gtest.h>
#include <pybind11/embed.h>  // Для работы с Python



int main(int argc, char **argv) {


    //     pybind11::scoped_interpreter guard{};
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

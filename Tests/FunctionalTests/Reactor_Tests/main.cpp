#include <gtest/gtest.h>
#include <Python.h>
#include <numpy/arrayobject.h>

int main(int argc, char **argv){
    Py_Initialize();
    //import_array();

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

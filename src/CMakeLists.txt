#set(BOOST_DIR ../external/boost_1_69_0)

include_directories(../inc)
#include_directories(${BOOST_DIR})

add_library(NeuralNetwork AddOper.cpp)

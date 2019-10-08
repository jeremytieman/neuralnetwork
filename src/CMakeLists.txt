set(HEADER_FILES ../inc/AddOper.h ../inc/Tensor.h)
set(SOURCE_FILES AddOper.cpp)

add_library(NeuralNetwork ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(NeuralNetwork PUBLIC ../inc/)
set_target_properties(NeuralNetwork PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/lib/)
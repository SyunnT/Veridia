project(${PROJECT_CORE}
    VERSION 0.1.0
    LANGUAGES CXX
)

add_library(${PROJECT_NAME} STATIC
    include/VeridiaCore.h
    src/VeridiaCore.cpp
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${TEMP_DIR}/lib
)
target_include_directories(${PROJECT_NAME} PRIVATE
    include
)

add_library(${TARGET_CORE_C_API} STATIC
    c_api/include/VeridiaCoreApi.h
    c_api/src/VeridiaCoreApi.cpp
)
set_target_properties(${TARGET_CORE_C_API} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${TEMP_DIR}/lib
)
target_include_directories(${TARGET_CORE_C_API} PRIVATE
    c_api/include
)
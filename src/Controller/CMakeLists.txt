# ----------------------------
# 源文件
# ----------------------------
set(SOURCES
    main.cpp
    Controller.cpp
)
set(HEADERS
    Controller.h
)

# ----------------------------
# 链接库
# ----------------------------
set(REQUIRED_LIBS
    Qt::Core
    Qt::Widgets
    Qt::Gui
    ${VIEW_MODULE_NAME}
)

# ----------------------------
# 目录
# ----------------------------
set(INCLUDE_DIRS
    ${VIEW_MODULE_DIR}
)
set(LINK_DIRECTORIES
)

# ----------------------------
# 创建目标
# ----------------------------
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${LINK_DIRECTORIES})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${REQUIRED_LIBS})

# ----------------------------
# 部署
# ----------------------------
add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME}
    POST_BUILD
    COMMAND ${QT_INSTALL_PATH}/bin/windeployqt.exe --verbose 0 $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
)

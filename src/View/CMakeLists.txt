project(${VIEW_MODULE_NAME})

# ----------------------------
# 源文件
# ----------------------------
set(SOURCES
    View.cpp
)
set(HEADERS
    view_global.h
    View.h
)
set(UIFILES
    View.ui
)
set(RESOURCES
    ${RESOURCES_DIR}/resources.qrc
)

# ----------------------------
# 链接库
# ----------------------------
set(REQUIRED_LIBS
    Qt::Core
    Qt::Widgets
    Qt::Gui
)

# ----------------------------
# 目录
# ----------------------------
set(INCLUDE_DIRS
)
set(LINK_DIRECTORIES
)

# ----------------------------
# 宏定义
# ----------------------------
set(DEFINITIONS
    EXPORT_VIEW_MODULE
)

# ----------------------------
# 创建目标
# ----------------------------
qt_add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UIFILES} ${RESOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${LINK_DIRECTORIES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${REQUIRED_LIBS})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${DEFINITIONS})

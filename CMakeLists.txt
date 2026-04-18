cmake_minimum_required(VERSION 3.26)
project(Veridia VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
    add_compile_options(/utf-8)
endif()

# ----------------------------
# 变量检查
# ----------------------------
if(NOT DEFINED QT_INSTALL_PATH)
    message(FATAL_ERROR "QT_INSTALL_PATH is not set")
endif()

set(CMAKE_PREFIX_PATH ${QT_INSTALL_PATH})

# ----------------------------
# Qt 配置
# ----------------------------
set(CMAKE_AUTORCC ON)
find_package(QT NAMES Qt6)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Core
    Widgets
    Gui
    LinguistTools
)
qt_standard_project_setup(
    I18N_SOURCE_LANGUAGE en_US
    I18N_TRANSLATED_LANGUAGES zh_CN
)

# ----------------------------
# 版本约束
# ----------------------------
if(${QT_VERSION} VERSION_LESS "6.9.0")
    message(FATAL_ERROR "Qt version must be at least 6.9.0")
endif()

# ----------------------------
# 项目配置导出
# ----------------------------
set(APP_REPOSITORY_URL "https://github.com/SyunnT/Veridia")
configure_file(
    ${CMAKE_SOURCE_DIR}/cmake/ProjectConfig.h.in
    ${CMAKE_BINARY_DIR}/generated/include/ProjectConfig.h
    @ONLY
)
include_directories(${CMAKE_BINARY_DIR}/generated/include)

# ----------------------------
# 子模块
# ----------------------------
# 目录配置
set(RESOURCES_DIR ${CMAKE_SOURCE_DIR}/resources)
set(TRANSLATIONS_DIR ${CMAKE_SOURCE_DIR}/translations)
# 视图模块
set(VIEW_MODULE_NAME ${PROJECT_NAME}_View)
set(VIEW_MODULE_DIR ${CMAKE_SOURCE_DIR}/src/View)
add_subdirectory(${VIEW_MODULE_DIR})
# 总模块
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Controller)
# 翻译文件
qt_add_translations(
    TARGETS ${VIEW_MODULE_NAME} ${CMAKE_PROJECT_NAME}
    RESOURCE_PREFIX /translations
    TS_OUTPUT_DIRECTORY ${TRANSLATIONS_DIR}
)
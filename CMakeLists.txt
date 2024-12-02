cmake_minimum_required(VERSION 3.27)
project(musicApp)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")


set(CMAKE_PREFIX_PATH "D:/myQt/mingw81_64_qt")
#set(CMAKE_PREFIX_PATH "E:/Qt/5.15.2/mingw81_64")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

add_executable(musicApp main.cpp
        ../resources/resources.qrc
        src/window_login/window_login.cpp
        src/window_login/window_login.h
        src/window_login/window_login.ui
        src/window_register/window_register.cpp
        src/window_register/window_register.h
        src/window_register/window_register.ui
        src/window_main/window_main.cpp
        src/window_main/window_main.h
        src/window_main/window_main.ui
        src/main/side_bar/side_bar.cpp
        src/main/side_bar/side_bar.h
        src/main/side_bar/side_bar.ui
        src/main/top_bar/top_bar.cpp
        src/main/top_bar/top_bar.h
        src/main/top_bar/top_bar.ui
        src/main/song_list/song_list.cpp
        src/main/song_list/song_list.h
        src/main/song_list/song_list.ui
        src/main/list_item/list_item.cpp
        src/main/list_item/list_item.h
        src/main/list_item/list_item.ui
        src/main/bottom_bar/bottom_bar.cpp
        src/main/bottom_bar/bottom_bar.h
        src/main/bottom_bar/bottom_bar.ui
        src/main/list_item/Song.cpp
        src/main/list_item/Song.h
        src/main/default_content/default_content.cpp
        src/main/default_content/default_content.h
        src/main/default_content/default_content.ui
        include/yaml.h
)
if (WIN32)
    set_target_properties(musicApp PROPERTIES WIN32_EXECUTABLE ON)
endif ()
# 包含 yaml-cpp 的头文件路径
target_include_directories(musicApp PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(musicApp
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        "${CMAKE_SOURCE_DIR}/lib_static/libyaml-cpp.a"
)

# 在编译可执行文件时，添加YAML_CPP_STATIC_DEFINE宏
target_compile_definitions(musicApp PUBLIC YAML_CPP_STATIC_DEFINE)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

cmake_minimum_required(VERSION 3.16)

project(PKW_HUD VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appPKW_HUD
    main.cpp
    heading.h heading.cpp
    velocity.h velocity.cpp
    position.h position.cpp
    rpm_bar_gauge.h rpm_bar_gauge.cpp
    velocitygauge.h velocitygauge.cpp
)

qt_add_qml_module(appPKW_HUD
    URI PKW_HUD
    VERSION 1.0
    QML_FILES main.qml HeadingSlider.qml
)

set_target_properties(appPKW_HUD PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPKW_HUD
    PRIVATE Qt6::Quick)

install(TARGETS appPKW_HUD
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

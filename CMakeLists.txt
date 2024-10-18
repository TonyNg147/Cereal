cmake_minimum_required(VERSION 3.16)

project(CerealExample LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Qml Gui Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Qml Gui Quick)

find_package(ConanIntegrate REQUIRED)

find_package(cereal REQUIRED)

add_executable(CerealExample
  main.cpp
)

add_subdirectory(Utils)
add_subdirectory(UI)
add_subdirectory(BoxModel)
add_subdirectory(StorageImpl)

target_link_libraries(CerealExample PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
  cereal::cereal
  Qt6::Qml
  Qt6::Gui
  UI
  StorageImpl
)

include(GNUInstallDirs)
install(TARGETS CerealExample
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

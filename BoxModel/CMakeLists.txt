set(SOURCES
    BoxListModel.cpp
    serialize/BoxInfo_s.cpp
    serialize/BoxListModel_s.cpp
)

add_library(BoxModel STATIC 
    ${SOURCES}
)

target_link_libraries(BoxModel PUBLIC   
    cereal::cereal 
    Qt6::Core
    Utils
)

target_include_directories(BoxModel PUBLIC ./)

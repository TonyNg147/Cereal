set(SOURCES
    serializeDeclare.h
)

add_library(Utils STATIC)

set_target_properties(Utils
    PROPERTIES
        LINKER_LANGUAGE CXX
)

target_include_directories(Utils INTERFACE ./)
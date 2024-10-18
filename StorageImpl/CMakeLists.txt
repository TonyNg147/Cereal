set(SOURCES
BoxStorage.cpp
)

add_library(StorageImpl STATIC ${SOURCES})

target_link_libraries(StorageImpl PUBLIC BoxModel)

target_include_directories(StorageImpl INTERFACE ./)


find_program(CONAN_EXECUTABLE REQUIRED NAMES conan)

if(NOT CONAN_SOURCE_PATH)
    set(CONAN_SOURCE_PATH ${CMAKE_SOURCE_DIR})
endif()

set(CONAN_ARGS install ${CONAN_SOURCE_PATH} --build=never --output-folder=${CMAKE_BINARY_DIR})

if(DEFINED CONAND_DEFAULT_PROFILE)
    list(APPEND CONAN_ARGS --profile=${CONAND_DEFAULT_PROFILE})
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    list(APPEND CONAN_ARGS -s arch=x86 -s:b arch=x86)
elseif()
    list(APPEND CONAN_ARGS -s arch=x86_64 -s:b arch=x86_64)
endif()

if(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "Must specify CMAKE_BUILD_TYPE")
endif()


list(APPEND CONAN_ARGS -s build_type=${CMAKE_BUILD_TYPE} -s:b build_type=${CMAKE_BUILD_TYPE})

set(DETECTED_COMPILER_TYPE "CXX")

if(NOT CMAKE_${DETECTED_COMPILER_TYPE}_COMPILER_ID AND CMAKE_C_COMPILER_ID)
    set(DETECTED_COMPILER_TYPE "C")
endif()


if(CMAKE_${DETECTED_COMPILER_TYPE}_COMPILER_ID STREQUAL "MSVC")
    list(APPEND CONAN_ARGS -s compiler=msvc)
    list(APPEND CONAN_ARGS -s compiler.runtime=dynamic)

    set(COMPILER_VERSION)
    
    if (MSVC_TOOLSET_VERSION EQUAL 143)
        set(COMPILER_VERSION 193)
    elseif(MSVC_TOOLSET_VERSION EQUAL 142)
        set(COMPILER_VERSION 192)
    elseif(MSVC_TOOLSET_VERSION EQUAL 141)
        set(COMPILER_VERSION 191)
    else()
        message(FATAL_ERROR "Unsupported MSVC toolset version " ${MSVC_TOOLSET_VERSION})
    endif()

    list(APPEND CONAN_ARGS -s compiler.version=${COMPILER_VERSION})
    list(APPEND CONAN_ARGS -s:b compiler.version=${COMPILER_VERSION})


elseif()
    message(FATAL_ERROR "Unsupported platform " CMAKE_${DETECTED_COMPILER_TYPE}_COMPILER_ID)
endif()


execute_process(
    COMMAND ${CONAN_EXECUTABLE} ${CONAN_ARGS} 
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

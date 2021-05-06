macro(initial_linksplatform_engine PROJECT_NAME)
    include(FetchContent)
    set(CMAKE_LOCAL_PROJECT_NAME ${PROJECT_NAME})
    set(LIST_REGISTERED_EXTENSIONS)
    get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)
endmacro()

macro(include_extension EXTENSION_NAME)
    add_subdirectory(${CMAKE_LOCAL_PROJECT_NAME}.${EXTENSION_NAME})
    target_link_libraries(${CMAKE_LOCAL_PROJECT_NAME}.${EXTENSION_NAME} PUBLIC ${CMAKE_LOCAL_PROJECT_NAME}.Library)
endmacro()

function(include_extension_if_support EXTENSION)
    message("Importing :: ${EXTENSION} ==> ${CMAKE_LOCAL_PROJECT_NAME}" \n)
    set(UP_EXTENSION ${EXTENSION})
    string(TOUPPER ${EXTENSION} UP_EXTENSION)
    if(DEFINED LINKS_PLATFORM_${UP_EXTENSION})
        if(${LINKS_PLATFORM_${UP_EXTENSION}})
            include_extension(${EXTENSION})
        endif()
    elseif(NOT IS_SUBPROJECT)
        include_extension(${EXTENSION})
    endif()
endfunction()

macro(include_test_framework)
    FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    )
    FetchContent_MakeAvailable(googletest)
    FetchContent_GetProperties(googletest)
    if(NOT googletest_POPULATED)
        FetchContent_Populate(googletest)
        add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
    endif()
    set(test_framework_libs gtest gtest_main)
endmacro()

macro(include_benchmark_framework)
    FetchContent_Declare(
            benchmark
            URL https://github.com/google/benchmark/archive/refs/tags/v1.5.3.zip
    )
    FetchContent_MakeAvailable(benchmark)
    FetchContent_GetProperties(benchmark)
    if(NOT benchmark_POPULATED)
        FetchContent_Populate(benchmark)
        add_subdirectory(${benchmark_SOURCE_DIR} ${benchmark_BINARY_DIR})
    endif()
    set(benchmark_framework_libs benchmark benchmark_main)
endmacro()


function(check_dependence DEPENDENCE_NAME)
    if (NOT EXISTS ${LINKS_PLATFORM_DIR}/${DEPENDENCE_NAME})
        execute_process(COMMAND git clone https://github.com/uselessgoddess/${DEPENDENCE_NAME}.git ${LINKS_PLATFORM_DIR}/)
    endif ()
endfunction()

function(add_dependence EXECUTABLE_NAME DEPENDENCE_NAME)
    set(DEPENDENCE_DIR ${LINKS_PLATFORM_DIR}/${DEPENDENCE_NAME}/cpp)
    add_subdirectory(${DEPENDENCE_DIR} ${LINKS_PLATFORM_DEPENDENCIES_DIR}/${DEPENDENCE_NAME}-build)
    target_link_libraries(${EXECUTABLE_NAME} INTERFACE Platform.${DEPENDENCE_NAME}.Library)
endfunction()

function(register_dependence EXECUTABLE_NAME DEPENDENCE_NAME)
    check_dependence(${DEPENDENCE_NAME})
    add_dependence(${EXECUTABLE_NAME} ${DEPENDENCE_NAME})
endfunction()

set(LINKS_PLATFORM_CXX_STANDARD 20)

macro(init_linksplatform_library)
    add_library(${CMAKE_LOCAL_PROJECT_NAME}.Library INTERFACE)
    target_include_directories(${CMAKE_LOCAL_PROJECT_NAME}.Library INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
    set_target_properties(${CMAKE_LOCAL_PROJECT_NAME}.Library PROPERTIES CMAKE_CXX_STANDARD ${LINKS_PLATFORM_CXX_STANDARD})
endmacro()
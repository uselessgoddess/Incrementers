include_test_framework()

add_executable(${CMAKE_LOCAL_PROJECT_NAME}.Tests IncrementerTests.cpp)
target_link_libraries(${CMAKE_LOCAL_PROJECT_NAME}.Tests PUBLIC ${CMAKE_LOCAL_PROJECT_NAME}.Library)
target_link_libraries(${CMAKE_LOCAL_PROJECT_NAME}.Tests PUBLIC ${test_framework_libs})

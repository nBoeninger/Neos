set(This DataObjectUnitTests)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(Sources ${TEST_SOURCES})

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    DataObject
    SlotsAndSignals
)

add_test(UnitTest_DataObject ${This})
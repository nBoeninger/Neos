set(This ValidReturnUnitTest)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(Sources ${TEST_SOURCES})

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    ValidReturn
)

add_test(UnitTest_ValidReturn ${This})
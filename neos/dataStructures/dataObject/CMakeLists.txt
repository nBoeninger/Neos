set(This DataObject)

project(${This} VERSION 0.0.0)

# Conditions for Framework
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE)

set(Headers
    "include/dataObject.hpp"
)
set(Sources
    "src/dataObject.cpp"
)

add_library(${This} STATIC ${Sources})
target_include_directories(${This} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${This} PUBLIC
    SlotsAndSignals
)
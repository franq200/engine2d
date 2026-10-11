add_library(engine STATIC src/Application.cpp)

target_include_directories(engine PUBLIC include)
target_compile_features(engine PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(engine PRIVATE /W4 /permissive-)
else()
    target_compile_options(engine PRIVATE -Wall -Wextra -Wpedantic)
endif()

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(engine PRIVATE SDL3::SDL3)
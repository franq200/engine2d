add_executable(sandbox src/main.cpp)
target_compile_features(sandbox PRIVATE cxx_std_20)

if(MSVC)
    target_compile_options(engine PRIVATE /W4 /permissive-)
else()
    target_compile_options(engine PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_link_libraries(sandbox PRIVATE engine)
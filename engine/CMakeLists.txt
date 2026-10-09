add_library(engine STATIC src/Application.cpp)

target_include_directories(engine PUBLIC include)
target_compile_features(engine PUBLIC cxx_std_20)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(engine PRIVATE SDL3::SDL3)
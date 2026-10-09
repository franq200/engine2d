add_executable(sandbox src/main.cpp)
target_compile_features(sandbox PRIVATE cxx_std_20)

target_link_libraries(sandbox PRIVATE engine)
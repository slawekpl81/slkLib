cmake_minimum_required(VERSION 3.10)
project(slk_lib VERSION 1.0)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodanie podkatalogów
add_subdirectory(src)

target_include_directories(slk_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

# Dodanie przykładowej aplikacji
add_subdirectory(examples)

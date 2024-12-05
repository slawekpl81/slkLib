# Tworzenie biblioteki
add_library(slk_lib STATIC lib.cpp)

# Dołączanie plików nagłówkowych
target_include_directories(slk_lib PUBLIC "${PROJECT_SOURCE_DIR}/../include")

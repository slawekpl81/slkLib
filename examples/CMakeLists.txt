# Tworzenie przykładowej aplikacji
add_executable(example main.cpp)

# Linkowanie z biblioteką
target_link_libraries(example PRIVATE slk_lib)

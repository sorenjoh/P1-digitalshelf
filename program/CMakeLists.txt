cmake_minimum_required(VERSION 3.16)
project(DigitalShelf LANGUAGES C)

# Alle programmets .c-filer bygges og linkes sammen.
add_executable(digitalshelf
    main.c
    main_menu.c
    login.c
    user_creation.c
    user_database.c
    movie_database.c
    preference_survey.c
    recommendation.c
    survey_questions.c
    ratings.c
)

# Brug standard C11 uden compiler-specifikke sprogudvidelser.
set_target_properties(digitalshelf PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS NO
)

# Advarsler hjaelper os med at opdage fejl under udviklingen.
if(MSVC)
    target_compile_options(digitalshelf PRIVATE /W4)
elseif(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(digitalshelf PRIVATE -Wall -Wextra -Wpedantic)
endif()

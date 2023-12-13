add_library(patient patient.c)
target_include_directories(patient PUBLIC .)

add_library(vitals vitals.c)
target_include_directories(vitals PUBLIC .)

add_library(symptoms symptoms.c)
target_include_directories(symptoms PUBLIC .)

add_library(controller controller.c)
target_include_directories(controller PUBLIC .)

add_library(triage_level triage_level.c)
target_include_directories(triage_level PUBLIC .)

add_library(menu menu.c)
target_include_directories(menu PUBLIC .)

add_library(file file.c)
target_include_directories(file PUBLIC .)

add_subdirectory(symptoms)

add_executable(main main.c)

target_link_libraries(main menu file controller patient symptoms symptoms_triage vitals triage_level)

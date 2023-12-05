add_library(gui gui.c)
target_include_directories(gui PUBLIC .)

add_library(patient_queue patient_queue.c)
target_include_directories(patient_queue PUBLIC .)

add_library(symptoms symptoms.c)
target_include_directories(symptoms PUBLIC .)

add_library(vitals vitals.c)
target_include_directories(vitals PUBLIC .)


add_executable(project1 project1.c)
target_link_libraries(project1 gui patient_queue symptoms vitals)

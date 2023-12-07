add_library(patient_queue patient_queue.c)
target_include_directories(patient_queue PUBLIC .)

add_library(symptoms symptoms.c)
target_include_directories(symptoms PUBLIC .)

add_library(vitals vitals.c)
target_include_directories(vitals PUBLIC .)

add_library(triage_level triage_level.c)
target_include_directories(triage_level PUBLIC .)

add_executable(main main.c)

target_link_libraries(main patient_queue symptoms vitals triage_level)

# if(WIN32 OR MSVC)
#         add_subdirectory(pdcurses)
#         target_link_libraries(main patient_queue symptoms vitals triage_level PRIVATE PDcurses)
# else()
#         find_package(Curses REQUIRED)
#         include_directories(${CURSES_INCLUDE_DIR})
#         target_link_libraries(main patient_queue symptoms vitals triage_level ${CURSES_LIBRARIES})
# endif()


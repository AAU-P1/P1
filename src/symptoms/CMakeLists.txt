add_library(symptoms symptoms.c)
target_include_directories(symptoms PUBLIC .)

add_library(symptoms_triage 
  001_abstinence.c
  002_allergic_symptoms.c
  )
target_include_directories(symptoms_triage PUBLIC .)

target_link_libraries(symptoms_triage symptoms)

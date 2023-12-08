add_library(gui 
  gui.c
  abstinence_gui.c
  vitals_gui.c
  symptoms_gui.c
  patient_queue_gui.c
  )
target_include_directories(gui PUBLIC .)

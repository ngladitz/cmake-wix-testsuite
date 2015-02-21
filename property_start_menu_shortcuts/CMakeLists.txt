add_executable(h-w hw.cpp)
install(TARGETS h-w DESTINATION bin)

install(FILES hw.cpp DESTINATION src)

set_property(INSTALL "bin/$<TARGET_FILE_NAME:h-w>"
  PROPERTY CPACK_START_MENU_SHORTCUTS "Hello World"
)

set_property(INSTALL "src/hw.cpp"
  PROPERTY CPACK_START_MENU_SHORTCUTS "Source Code" "Same Source Code"
)

include(CPack)

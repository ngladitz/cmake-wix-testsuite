add_executable(hw hw.cpp)
install(TARGETS hw DESTINATION bin)

install(FILES hw.cpp DESTINATION src
  PERMISSIONS OWNER_READ
)

include(CPack)
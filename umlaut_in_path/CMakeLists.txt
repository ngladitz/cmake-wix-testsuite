add_executable(hw hw.cpp)
install(TARGETS hw DESTINATION bün)

install(FILES hw.cpp töst.txt DESTINATION süc)

include(CPack)
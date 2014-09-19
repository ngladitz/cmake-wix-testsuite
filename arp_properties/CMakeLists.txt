add_executable(hw hw.cpp)
install(TARGETS hw DESTINATION bin)

install(FILES hw.cpp DESTINATION src)

set(CPACK_WIX_PROPERTY_ARPCOMMENTS "My Comment")

include(CPack)

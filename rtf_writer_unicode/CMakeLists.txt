add_executable(hw hw.cpp)
install(TARGETS hw DESTINATION bin)

install(FILES hw.cpp DESTINATION src)

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/license.txt")

include(CPack)
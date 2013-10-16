add_library(mylib mylib.cpp)

add_executable(mylibapp mylibapp.cpp)
target_link_libraries(mylibapp mylib)

install(TARGETS mylib ARCHIVE DESTINATION lib COMPONENT libraries)
install(TARGETS mylibapp RUNTIME DESTINATION bin COMPONENT applications)
install(FILES mylib.h DESTINATION include COMPONENT headers)

set(CPACK_COMPONENTS_ALL applications libraries headers)

set(CPACK_COMPONENT_APPLICATIONS_DISPLAY_NAME "MyLib Application")
set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Libraries")
set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C++ Headers")

set(CPACK_COMPONENT_APPLICATIONS_DESCRIPTION 
	"An extremely useful application that makes use of MyLib")
set(CPACK_COMPONENT_LIBRARIES_DESCRIPTION
	"Static libraries used to build programs with MyLib")
set(CPACK_COMPONENT_HEADERS_DESCRIPTION
	"C/C++ header files for use with MyLib")

set(CPACK_COMPONENT_HEADERS_DEPENDS libraries)

set(CPACK_COMPONENT_APPLICATIONS_GROUP "Runtime")
set(CPACK_COMPONENT_LIBRARIES_GROUP "Development")
set(CPACK_COMPONENT_HEADERS_GROUP "Development")

set(CPACK_COMPONENT_GROUP_DEVELOPMENT_DESCRIPTION
	"All of the tools you'll ever need to develop software")

set(CPACK_ALL_INSTALL_TYPES Full Developer)

set(CPACK_COMPONENT_LIBRARIES_INSTALL_TYPES Developer Full)
set(CPACK_COMPONENT_HEADERS_INSTALL_TYPES Developer Full)
set(CPACK_COMPONENT_APPLICATIONS_INSTALL_TYPES Full)

include(CPack)

cmake_minimum_required(VERSION 2.8.12)

include(CPackComponent)

add_library(mylib mylib.cpp)

add_executable(mylibapp mylibapp.cpp)
target_link_libraries(mylibapp mylib)

install(TARGETS mylib ARCHIVE DESTINATION lib COMPONENT libraries)
install(TARGETS mylibapp RUNTIME DESTINATION bin COMPONENT applications)
install(FILES mylib.h DESTINATION include COMPONENT headers)
install(FILES free.txt DESTINATION doc)

#set(CPACK_COMPONENTS_ALL applications libraries headers)

cpack_add_component(applications
    DISPLAY_NAME "MyLib Application"
    DESCRIPTION "An extremely useful application that makes use of MyLib"
    GROUP "Runtime"
)

cpack_add_component(libraries
    DISPLAY_NAME "Libraries"
    DESCRIPTION "Static libraries used to build programs with MyLib"
    HIDDEN
    GROUP "Development"
)

cpack_add_component(headers
    DISPLAY_NAME "C++ Headers"
    DESCRIPTION "C/C++ header files for use with MyLib"
    DEPENDS libraries
    GROUP "Development"
)

cpack_add_component_group(Runtime)

cpack_add_component_group(Development
    DESCRIPTION "All of the tools you'll ever need to develop software"
)

set(CPACK_COMPONENT_GROUP_DEVELOPMENT_PARENT_GROUP "Runtime")
#unset(CPACK_COMPONENT_APPLICATIONS_REQUIRED)

set(CPACK_ALL_INSTALL_TYPES Full Developer)

set(CPACK_COMPONENT_LIBRARIES_INSTALL_TYPES Developer Full)
set(CPACK_COMPONENT_HEADERS_INSTALL_TYPES Developer Full)
set(CPACK_COMPONENT_APPLICATIONS_INSTALL_TYPES Full)

include(CPack)

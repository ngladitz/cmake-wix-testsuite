cmake_minimum_required(VERSION 3.6)

include(CPackComponent)

install(FILES my_component.txt DESTINATION doc1 COMPONENT my_component1)
install(FILES my_component.txt DESTINATION doc2 COMPONENT my_component2)

cpack_add_component(my_component1
    DISPLAY_NAME "My Component 1"
    DESCRIPTION "My Component Description 1"
    GROUP "MyGroup"
)

cpack_add_component(my_component2
    DISPLAY_NAME "My Component 2"
    DESCRIPTION "My Component Description 2"
    GROUP "MyGroup"
)

cpack_add_component_group(MyGroup
    DESCRIPTION "My Component Group Description"
)

set(CPACK_WIX_PATCH_FILE "${CMAKE_CURRENT_SOURCE_DIR}/patch.xml")

include(CPack)

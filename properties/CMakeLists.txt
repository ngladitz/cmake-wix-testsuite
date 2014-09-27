install(FILES never_overwrite.txt DESTINATION test1)
install(FILES permanent.txt DESTINATION test2)
install(FILES permanent_and_never_overwrite.txt DESTINATION test3)
install(FILES
    acl_generic_all.txt
    acl_generic_write.txt
    acl_mixed.txt
    DESTINATION acl
)

install(
    DIRECTORY
        empty_directory_with_property
        non_empty_directory_with_property
        empty_directory
        non_empty_directory
    DESTINATION ./
    PATTERN "ignore.me" EXCLUDE
)

set_property(INSTALL
  test1/never_overwrite.txt
  test3/permanent_and_never_overwrite.txt
  PROPERTY CPACK_NEVER_OVERWRITE ON
)

set_property(INSTALL
  test2/permanent.txt
  test3/permanent_and_never_overwrite.txt
  PROPERTY CPACK_PERMANENT ON
)

set_property(INSTALL
  acl/acl_generic_all.txt
  PROPERTY CPACK_WIX_ACL "Everyone=GenericAll"
)

set_property(INSTALL
  acl/acl_generic_write.txt
  PROPERTY CPACK_WIX_ACL "Everyone=GenericWrite"
)

set_property(INSTALL
  acl/acl_mixed.txt
  PROPERTY CPACK_WIX_ACL "Everyone=GenericRead,Read,ReadPermission,Delete"
)

set_property(INSTALL
    empty_directory_with_property
    non_empty_directory_with_property
    PROPERTY CPACK_WIX_ACL "Everyone=GenericRead,GenericWrite,CreateFile"
)

include(CPack)

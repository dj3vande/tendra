# Copyright 2002-2011, The TenDRA Project.
# Copyright 1997, United Kingdom Secretary of State for Defence.
#
# See doc/copyright/ for the full copyright terms.


+USE "svid/svid3", "", "config" ;
+IF %% __SYSV_ENHANCED_SECURITY %%

+USE "svid/svid3", "sys/types.h.ts" ;
+USE "svid/svid3", "sys/ipc.h.ts" ;

+CONST int USER_OBJ, USER, GROUP_OBJ, GROUP, CLASS_OBJ, OTHER_OBJ ;
+CONST int DEF_USER_OBJ, DEF_USER, DEF_GROUP_OBJ, DEF_GROUP ;
+CONST int DEF_CLASS_OBJ, DEF_OTHER_OBJ ;
+CONST int ACL_SET, ACL_GET, ACL_CNT ;

+FIELD struct acl | acl_struct {
    int a_type ;
    uid_t a_id ;
    unsigned short a_perm ;
} ;

+FUNC int acl ( char *, int, int, struct acl * ) ;
+FUNC int aclipc ( int, int, int, int, struct acl * ) ;
+FUNC int aclsort ( int, int, struct acl * ) ;

+ENDIF

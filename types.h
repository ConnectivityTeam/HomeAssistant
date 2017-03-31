#ifndef HA_TYPES_H
#define HA_TYPES_H

#define DEBUG

struct user {
    const char *username = "";
    unsigned int uid = 0;
    const char *prename = "";
    const char *name = "";
    const char *password = "";
    unsigned int groups = 0;
};

struct group {
    const char *groupname;
    unsigned int gid;
};

typedef user t_user;
typedef group t_group;

#endif // HA_TYPES_H

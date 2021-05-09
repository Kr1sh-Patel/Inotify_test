#ifndef COMMON_H
#define COMMON_H

#ifdef __FreeBSD__
#define stat64 stat
#define lstat64 lstat
#ifdef DEFAULT_FANOTIFY
#error "FreeBSD does not support fanotify"
#endif
#endif

#include <stdbool.h>

#define BLOCKING_TIMEOUT -1

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#endif
#define EXIT_TIMEOUT 2

#ifdef DEFAULT_FANOTIFY
#define DEFAULT_FANOTIFY_MODE 1
#else
#define DEFAULT_FANOTIFY_MODE 0
#endif

void print_event_descriptions();
int isdir(char const *path);

typedef struct {
    char const **watch_files;
    char const **exclude_files;
} FileList;
FileList construct_path_list(int argc, char **argv, char const *filename);

void warn_inotify_init_error(int fanotify);

bool is_timeout_option_valid(long int *timeout, char *optarg);

#endif

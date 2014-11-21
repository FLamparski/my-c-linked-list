#ifndef _debug_h_
#define _debug_h_

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "D/%s %s:%d " M "\n", \
  __func__, __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "E/%s %s:%d (Errno: %s) " M "\n", \
  __func__, __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "W/%s %s:%d (Errno: %s) " M "\n", \
  __func__, __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "I/%s %s:%d " M "\n", \
  __func__, __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if (!(A)) { log_err(M, ##__VA_ARGS__); \
  errno = 0; goto error; }

#define sentinel(M, ...) { log_err(M, ##__VA_ARGS__); errno = 0; \
  goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); \
  errno = 0; goto error; }

#endif

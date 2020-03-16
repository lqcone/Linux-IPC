

#include	<stdarg.h>		/* ANSI C header file */
#include	<syslog.h>		/* for syslog() */

int		daemon_proc;		/* set nonzero by daemon_init() */

static void	err_doit(int, int, const char*, va_list);

/* Nonfatal error related to a system call.
 * Print a message and return. */

 /* $$.ix [err_ret]~function,~source~code$$ */
void
err_ret(const char* fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	err_doit(1, LOG_INFO, fmt, ap);
	va_end(ap);
	return;
}
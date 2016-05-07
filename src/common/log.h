/*
This file is part of iprohc.

iprohc is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
any later version.

iprohc is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with iprohc.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef IPROHC_LOG_H
#define IPROHC_LOG_H

#include <syslog.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

extern int log_max_priority;
extern bool iprohc_log_stderr;

static inline void trace(int priority, const char *format, ...)
	__attribute__((format(printf, 2, 3)));

static inline void trace(int priority, const char *format, ...)
{
	va_list args;

	if(priority <= log_max_priority)
	{
		va_start(args, format);
		vsyslog(LOG_MAKEPRI(LOG_DAEMON, priority), format, args);
		va_end(args);

		if(iprohc_log_stderr && priority <= LOG_NOTICE)
		{
			va_start(args, format);
			vfprintf(stderr, format, args);
			fprintf(stderr, "\n");
			va_end(args);
		}
	}

}


#endif


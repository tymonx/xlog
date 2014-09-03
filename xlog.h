/*!
 * @copyright Copyright (c) 2014, Tymoteusz Blazejczyk - www.tymonx.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of xlog nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _XLOG_H_
#define _XLOG_H_

#define XLOG_FILE_NAME          __FILE__
#define XLOG_FUNCTION_NAME      __FUNCTION__
#define XLOG_LINE_NUMBER        __LINE__

enum xlog_level {
    XLOG_EMERGENCY      = 0,
    XLOG_ALERT          = 1,
    XLOG_CRITICAL       = 2,
    XLOG_ERROR          = 3,
    XLOG_WARNING        = 4,
    XLOG_NOTICE         = 5,
    XLOG_INFO           = 6,
    XLOG_DEBUG          = 7,
    XLOG_LEVEL_MAX      = 8
};

struct xlog {
    unsigned int id;
    enum xlog_level level;
};

struct xlog_buffer {
    char* data;
    unsigned int size;
};

void xlog_buffer_create(struct xlog* inst, const enum xlog_level level,
        struct xlog_buffer* buffer);

void xlog_buffer_init(struct xlog* inst, const enum xlog_level level,
        struct xlog_buffer* buffer);

void xlog_buffer_write(struct xlog* inst, const enum xlog_level level,
        struct xlog_buffer* buffer, const char* fmt, ...);

void xlog_buffer_destroy(struct xlog* inst, const enum xlog_level level,
        struct xlog_buffer* buffer);

char* xlog_buffer_get_data(struct xlog_buffer* buffer) {
    return buffer->data;
}

unsigned int xlog_buffer_get_size(struct xlog_buffer* buffer) {
    return buffer->size;
}

void _xlog_write(struct xlog* inst, const enum xlog_level level,
        const char* file_name,
        const char* function_name,
        const unsigned int line_number,
        const char* fmt, ...);

#define xlog_write(inst, level, ...)\
    _xlog_write((inst), (level),\
            XLOG_FILE_NAME,\
            XLOG_FUNCTION_NAME,\
            XLOG_LINE_NUMBER,\
            __VA_ARGS__)

#endif /* _XLOG_H_ */

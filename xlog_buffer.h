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

#ifndef _XLOG_BUFFER_H_
#define _XLOG_BUFFER_H_

#include "xlog.h"

struct xlog_buffer {
    char* data;
    size_t size;
};

void xlog_buffer_create(struct xlog* inst, const enum xlog_level level,
        struct xlog_buffer* buffer);

void xlog_buffer_init(struct xlog* inst, const enum xlog_level level,
        struct xlog_buffer* buffer);

void xlog_buffer_write(struct xlog* inst, const enum xlog_level level,
        struct xlog_buffer* buffer, const char* fmt, ...);

void vxlog_buffer_write(struct xlog* inst, const enum xlog_level level,
        struct xlog_buffer* buffer, const char* fmt, va_list args);

void xlog_buffer_destroy(struct xlog* inst, const enum xlog_level level,
        struct xlog_buffer* buffer);

char* xlog_buffer_get_data(struct xlog_buffer* buffer) {
    return buffer->data;
}

size_t xlog_buffer_get_size(struct xlog_buffer* buffer) {
    return buffer->size;
}

#endif /* _XLOG_BUFFER_H_ */

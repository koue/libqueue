/*
 * Copyright (c) 2018-2023 Nikola Kolev <koue@chaosophia.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *    - Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    - Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _LIBQUEUE_H_
#define _LIBQUEUE_H_

#include <sys/queue.h>

struct queue_entry {
	TAILQ_ENTRY(queue_entry) entry;
	char *name;
	char *value;
};

struct queue {
	TAILQ_HEAD(, queue_entry) head;
};


/*
** FILE
*/
int queue_file(const char *filename, struct queue *queue);

/*
** QUEUE
*/
void queue_init(struct queue *queue);
#define qi queue_init
int queue_add(struct queue *queue, const char *name, const char *value);
#define qa queue_add
char *queue_get(struct queue *queue, const char *name);
#define qg queue_get
const char *queue_check(struct queue *queue, const char **params);
#define qc queue_check
int queue_update(struct queue *queue, const char *name, const char *value);
#define qu queue_update
int queue_remove(struct queue *queue, const char *name);
#define qr queue_remove
void queue_print(struct queue *queue);
void queue_purge(struct queue *queue);
#define qp queue_purge

#endif

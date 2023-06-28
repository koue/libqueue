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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libqueue.h"
#include "test.h"

int
main(void)
{
	struct queue cgi, config;
	static const char *params[] = { "name1", "name2", NULL };

	test_start();
	queue_init(&cgi);
	queue_init(&config);
	assert(queue_get(&cgi, NULL) == NULL);
	assert(queue_get(&cgi, "name1") == NULL);
	assert(queue_update(&cgi, "name1", "value") == -1);
	assert(queue_get(&config, "param4") == NULL);
	assert(queue_add(&cgi, NULL, NULL) == -1);
	assert(queue_add(&cgi, "name1", NULL) == -1);
	assert(queue_add(&cgi, NULL, "black sheep wall") == -1);
	assert(queue_add(&cgi, "name1", "black sheep wall") == 0);
	assert(queue_add(&cgi, "name1", "show me the money") == -1);
	assert(queue_add(&cgi, "name2", "power overwhelming") == 0);
	assert(queue_file("./configrc", &config) == 0);
	assert(queue_check(&cgi, NULL) == NULL);
	assert(queue_check(&cgi, params) == NULL);
	assert(queue_check(&config, params) != NULL);
	assert(strcmp(queue_get(&cgi, "name1"), "black sheep wall") == 0);
	assert(queue_get(&config, "param3") == NULL);
	assert(strcmp(queue_get(&config, "param4"), "power 'overwhelming'") == 0);
	assert(queue_update(&config, NULL, NULL) == -1);
	assert(queue_update(&config, "param4", NULL) == -1);
	assert(queue_update(&config, NULL, "my new value") == -1);
	assert(queue_update(&config, "param4", "my new value") == 0);
	assert(strcmp(queue_get(&config, "param4"), "my new value") == 0);
	assert(queue_remove(&config, NULL) == -1);
	assert(queue_remove(&config, "param4") == 0);
	assert(queue_get(&config, "param4") == NULL);
	queue_purge(&cgi);
	queue_purge(&config);

	return (0);
}

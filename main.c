/*
 * Copyright (c) 2009-2010 Jack Christopher Kastorff <encryptio@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdint.h>
#include <string.h>
#include <convolute.h>
#include <die.h>

static uint32_t str2time(int sr, char *str)
{
    int len = strlen(str);
    char last = str[len - 1];
    switch(last) {
        case 's':
            str[len - 1] = '\0';
            return atof(str) * sr;
            break;
        default:
            return atoi(str);
            break;
    }
}

int main(int argc, char **argv) {
    if ( argc != 5 )
        die("Bad number of arguments. Usage: convolute impulse amp sr time");

    convolute(argv[1], atof(argv[2]), str2time(atoi(argv[3]), argv[4]));
}


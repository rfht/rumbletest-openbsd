/*
 * Copyright (c) 2024 Thomas Frohwein
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

#include <sys/ioctl.h>

#include <err.h>
#include <fcntl.h>
#include <stdio.h>

#include <dev/usb/ujoyio.h>

int main(int argc, char** argv) {
	struct ujoy_rumble ur = { GIP_MOTOR_ALL, 0x32, 0x32, 0x32,
				  0x32, 0x0c, 0x00, 0x00 };
	int fd;

	if ((fd = open("/dev/ujoy/0", O_RDONLY | O_CLOEXEC)) == -1)
		err(1, "error while trying to open file descriptor");
	if (ioctl(fd, UJOYIO_RUMBLE, &ur) < 0)
		err(1, "ioctl error");

	return (0);
}

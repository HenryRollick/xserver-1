/*
 * Copyright 2004 by Costas Stylianou <costas.stylianou@psion.com> +44(0)7850 394095
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Costas Sylianou not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission. Costas Stylianou makes no representations
 * about the suitability of this software for any purpose.  It is provided
 * "as is" without express or implied warranty.
 *
 * COSTAS STYLIANOU DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL COSTAS STYLIANOU BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
/*
 * epson13806stub.c
 *
 * History:
 * 28-Jan-04  C.Stylianou       PRJ NBL: Created from fbdevinit.c
 *
 */

#ifdef HAVE_CONFIG_H
#include <kdrive-config.h>
#endif
#include "epson13806.h"

KdCardFuncs epsonFuncs = {
    epsonCardInit,          /* cardinit */
    epsonScreenInit,        /* scrinit */
    epsonInitScreen,        /* initScreen */
    epsonFinishInitScreen,
    epsonCreateResources,
    epsonPreserve,          /* preserve */
    epsonEnable,            /* enable */
    epsonDPMS,              /* dpms */
    epsonDisable,           /* disable */
    epsonRestore,           /* restore */
    epsonScreenFini,        /* scrfini */
    epsonCardFini,          /* cardfini */

    0,                      /* initCursor */
    0,                      /* enableCursor */
    0,                      /* disableCursor */
    0,                      /* finiCursor */
    0,                      /* recolorCursor */

    epsonDrawInit,          /* initAccel */
    epsonDrawEnable,        /* enableAccel */
    epsonDrawDisable,       /* disableAccel */
    epsonDrawFini,          /* finiAccel */

    epsonGetColors,         /* getColors */
    epsonPutColors,         /* putColors */
};

void
InitCard (char *name)
{
    fprintf(stdout, "Epson 13806 Tiny X Driver ver 1.10\n");

    KdCardInfoAdd (&epsonFuncs, 0);
}

void
InitOutput (ScreenInfo *pScreenInfo, int argc, char **argv)
{
    KdInitOutput (pScreenInfo, argc, argv);
}

void
InitInput (int argc, char **argv)
{
    KdOsAddInputDrivers ();
    KdInitInput ();
}

void
CloseInput (void)
{
    KdCloseInput ();
}

int
ddxProcessArgument (int argc, char **argv, int i)
{
    if (!strcmp (argv[i], "-fb"))
    {
        if (i+1 < argc)
        {
            fbdevDevicePath = argv[i+1];
            return 2;
        }
        UseMsg();
        exit(1);
    }

    return KdProcessArgument (argc, argv, i);
}

void
ddxUseMsg (void)
{
    KdUseMsg();
    ErrorF("\nXepson Device Usage:\n");
    ErrorF("-fb path         Framebuffer device to use. Defaults to /dev/fb0\n");
}
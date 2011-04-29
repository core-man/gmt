/*--------------------------------------------------------------------
 *	$Id: pslib.h,v 1.69 2011-04-29 03:08:12 guru Exp $
 *
 *	Copyright (c) 2009-2011 by P. Wessel and R. Scharroo
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; version 2 or any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *--------------------------------------------------------------------*/
/*
 * This include file must be included by all programs using pslib.a
 *
 * Authors:	Paul Wessel, Dept. of Geology and Geophysics, SOEST, U Hawaii
 *			   pwessel@hawaii.edu
 *		Remko Scharroo, Altimetrics
 *			   remko@altimetrics.com
 * Version:	5.0 [64-bit enabled API edition]
 * Date:	15-OCT-2009
 */

#ifndef _PSLIB_H
#define _PSLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

/* Declaration of type PSL_LONG */

#ifdef _WIN64
typedef __int64 PSL_LONG;	/* A signed 8-byte integer */
#define PSL_LL "ll"
#else
typedef long PSL_LONG;		/* A signed 4 (or 8-byte for 64-bit) integer */
#define PSL_LL "l"
#endif

/* Declaration modifiers for DLL support (MSC et al) */

#if defined(DLL_PSL)		/* define when library is a DLL */
#if defined(DLL_EXPORT)		/* define when building the library */
#define MSC_EXTRA_PSL __declspec(dllexport)
#else
#define MSC_EXTRA_PSL __declspec(dllimport)
#endif
#else
#define MSC_EXTRA_PSL
#endif				/* defined(DLL_PSL) */

/* Unless DLL_PSL is defined, EXTERN_MSC is simply extern */

#ifndef EXTERN_MSC
#define EXTERN_MSC extern MSC_EXTRA_PSL
#endif

/* Number of PostScript points in one inch */

#define PSL_POINTS_PER_INCH	72.0

#define PSL_BUFSIZ	4096	/* To match GMT_BUFSIZ and be consistent across all platforms */

/* PSL codes for geometric symbols as expected by PSL_plotsymbol */

#define PSL_STAR		((PSL_LONG)'a')
#define PSL_CIRCLE		((PSL_LONG)'c')
#define PSL_DIAMOND		((PSL_LONG)'d')
#define PSL_ELLIPSE		((PSL_LONG)'e')
#define PSL_HEXAGON		((PSL_LONG)'h')
#define PSL_OCTAGON		((PSL_LONG)'g')
#define PSL_INVTRIANGLE		((PSL_LONG)'i')
#define PSL_ROTRECT		((PSL_LONG)'j')
#define PSL_MARC		((PSL_LONG)'m')
#define PSL_PENTAGON		((PSL_LONG)'n')
#define PSL_DOT			((PSL_LONG)'p')
#define PSL_RECT		((PSL_LONG)'r')
#define PSL_SQUARE		((PSL_LONG)'s')
#define PSL_TRIANGLE		((PSL_LONG)'t')
#define PSL_VECTOR		((PSL_LONG)'v')
#define PSL_WEDGE		((PSL_LONG)'w')
#define PSL_CROSS		((PSL_LONG)'x')
#define PSL_YDASH		((PSL_LONG)'y')
#define PSL_PLUS		((PSL_LONG)'+')
#define PSL_XDASH		((PSL_LONG)'-')

/* PSL codes for arguments of PSL_beginplot and other routines */

#define PSL_CM			0
#define PSL_INCH		1
#define PSL_METER		2
#define PSL_PT			3
#define PSL_FINALIZE		1
#define PSL_OVERLAY		1
#define PSL_INIT		0
#define PSL_LANDSCAPE		0
#define PSL_PORTRAIT		1
#define PSL_ASCII85		0
#define PSL_HEX			1
#define PSL_NONE		0
#define PSL_RLE			1
#define PSL_LZW			2
#define PSL_NO			0
#define PSL_YES			1
#define PSL_FWD			0
#define PSL_INV			1
#define PSL_OUTLINE		1

/* PSL codes for pen movements (used by PSL_plotpoint, PSL_plotline, PSL_plotarc) */

#define PSL_DRAW		0
#define PSL_MOVE		1
#define PSL_STROKE		2
#define PSL_REL			4
#define PSL_CLOSE		8

/* PSL codes for text justification */

#define PSL_BL			1
#define PSL_BC			2
#define PSL_BR			3
#define PSL_ML			5
#define PSL_MC			6
#define PSL_MR			7
#define PSL_TL			9
#define PSL_TC			10
#define PSL_TR			11

/* PSL code for paragraph justification */

#define PSL_JUST		4

/* PSL code for rectangle shapes */

#define PSL_RECT_STRAIGHT	0
#define PSL_RECT_ROUNDED	1
#define PSL_RECT_CONVEX		2
#define PSL_RECT_CONCAVE	3

/* PSL codes for line settings */

#define PSL_BUTT_CAP		0
#define PSL_ROUND_CAP		1
#define PSL_SQUARE_CAP		2
#define PSL_MITER_JOIN		0
#define PSL_ROUND_JOIN		1
#define PSL_BEVEL_JOIN		2
#define PSL_MITER_DEFAULT	35

/* Verbosity levels */

#define PSL_MSG_SILENCE		0	/* No messages whatsoever */
#define PSL_MSG_FATAL		1	/* Fatal messages */
#define PSL_MSG_NORMAL		2	/* Warnings level -V */
#define PSL_MSG_VERBOSE		3	/* Longer verbose, -Vl in some programs */
#define PSL_MSG_DEBUG		4	/* Debug messages for developers mostly */

/* Color spaces */

#define PSL_RGB			0
#define PSL_CMYK		1
#define PSL_HSV			2
#define PSL_GRAY		3

/* Color types */

#define PSL_IS_STROKE		0
#define PSL_IS_FILL		1
#define PSL_IS_FONT		2

/* Positioning types */

#define PSL_ABS			1

/* Clipping types */

#define PSL_ALL_CLIP_TXT	0	/* Terminates all textpath-based clipping */
#define PSL_ALL_CLIP_POL	INT_MAX	/* Terminates all textpath-based clipping */

/* PSL error codes */

#define PSL_NO_ERROR		 0	/* No errors, all is OK */
#define PSL_NO_SESSION		-1	/* No active session */
#define PSL_BAD_FLAG		-2	/* A flag is outside required range */
#define PSL_BAD_RANGE		-3	/* Range defined by min/max exceeds limit */
#define PSL_BAD_SIZE		-4	/* Size is negative */
#define PSL_BAD_SYMBOL		-5	/* Unknown symbol type */
#define PSL_NO_PATH		-6	/* Less than 2 points given as path */
#define PSL_BAD_WIDTH		-7	/* Negative line width */
#define PSL_BAD_TEXT		-8	/* Text is too long */
#define PSL_NO_POLYGON		-9	/* Less than 3 points */
#define PSL_READ_FAILURE	-10	/* Less than 3 points */
#define PSL_BAD_JUST		-11	/* Bad text or paragraph justification */
#define PSL_BAD_VALUE		-12	/* Bad value */

/*--------------------------------------------------------------------
 *			PSL PARAMETERS DEFINITIONS
 *--------------------------------------------------------------------*/

#define PSL_N_PATTERNS		91	/* Current number of predefined patterns + 1, # 91 is user-supplied */
#define PSL_MAX_EPS_FONTS	6

/* Single, global structure used internally by pslib */

struct EPS {    /* Holds info for eps files */
/* For Encapsulated PostScript Headers:

	You will need to supply a pointer to an EPS structure in order to
	get correct information in the EPS header.  If you pass a NULL pointer
	instead you will get default values for the BoundingBox plus no
	info is provided about the users name, document title, and fonts used.
	To fill in the structure you must:

	- Determine the extreme dimensions of your plot in points (1/72 inch).
	- Supply the user's name (or NULL)
	- Supply the document's title (or NULL)
	- Set the font values to the ids of the fonts used  First unused font must be set
 	  to -1.  E.g., if 4 fonts are used, font[0], font[1], font[2], and
	  font[3] must contain the integer ID of these fonts; font[4] = -1
*/
	double x0, x1, y0, y1;		/* Bounding box values in points */
	int portrait;			/* TRUE if start of plot was portrait */
	int clip_level;			/* Add/sub 1 as we clip/unclip - should end at 0 */
	int fontno[PSL_MAX_EPS_FONTS];	/* Array with font ids used (skip if -1). 6 is max fonts used in GMT anot/labels */
	char *name;			/* User name */
	char *title;			/* Plot title */
};

struct PSL_CTRL {
	struct INIT {	/* Parameters set by user via PSL_beginplot() */
		FILE *err;			/* Error stream (NULL means stderr)		*/
		char *encoding;			/* The encoding name. e.g. ISO-8859-1		*/
		char *session;			/* The session name (NULL)			*/
		PSL_LONG unit;			/* 0 = cm, 1 = inch, 2 = meter			*/
		PSL_LONG copies;		/* Number of copies for this plot		*/
		double page_rgb[4];		/* RGB color for background paper [white]	*/
		double page_size[2];		/* Width and height of paper used in points	*/
		double dpi;			/* Selected dots per inch			*/
		double magnify[2];		/* Global scale values [1/1]			*/
		double origin[2];		/* Origin offset [1/1]				*/
		struct EPS *eps;		/* structure with Document info			*/
	} init;
	struct CURRENT {	/* Variables and settings that changes via PSL_* calls */
		char string[PSL_BUFSIZ];	/* Last text string plotted			*/
		char style[512];		/* Current setdash pattern			*/
		char bw_format[8];		/* Format used for grayshade value		*/
		char rgb_format[64];		/* Same, for RGB color triplets			*/
		char hsv_format[64];		/* Same, for HSV color triplets	(HSB in PS)	*/
		char cmyk_format[64];		/* Same, for CMYK color quadruples		*/
		char transparency_mode[16];	/* PDF transparency mode			*/
		double linewidth;		/* Current pen thickness			*/
		double rgb[3][4];		/* Current stroke, fill, and fs fill rgb	*/
		double offset;			/* Current setdash offset			*/
		double fontsize;		/* Current font size				*/
		PSL_LONG font_no;		/* Current font number				*/
		PSL_LONG outline;		/* Current outline				*/
	} current;
	struct INTERNAL {	/* Variables used internally only */
		char *SHAREDIR;			/* Pointer to path of directory with pslib subdirectory */
		char *USERDIR;			/* Pointer to path of directory with user definitions (~/.gmt) */
		char *user_image[PSL_N_PATTERNS];	/* Name of user patterns		*/
		PSL_LONG verbose;		/* TRUE for verbose output, FALSE remains quiet	*/
		PSL_LONG comments;		/* TRUE for writing comments to output, FALSE strips all comments */
		PSL_LONG overlay;		/* TRUE if overlay (-O)				*/
		PSL_LONG landscape;		/* TRUE = Landscape, FALSE = Portrait		*/
		PSL_LONG text_init;		/* TRUE after PSL_text.ps has been loaded	*/
		PSL_LONG image_format;		/* 0 writes images in ascii, 2 uses binary	*/
		PSL_LONG absolute;		/* TRUE will reset origin, FALSE means relative position	*/
		PSL_LONG eps_format;		/* TRUE makes EPS file, FALSE means PS file	*/
		PSL_LONG N_FONTS;		/* Total no of fonts;  To add more, modify the file CUSTOM_font_info.d */
		PSL_LONG compress;		/* Compresses images with (1) RLE or (2) LZW or (0) None */
		PSL_LONG color_mode;		/* 0 = rgb, 1 = cmyk, 2 = hsv (only 1-2 for images)	*/
		PSL_LONG line_cap;		/* 0, 1, or 2 for butt, round, or square [butt] */
		PSL_LONG line_join;		/* 0, 1, or 2 for miter, arc, or bevel [miter] */
		PSL_LONG miter_limit;		/* Acute angle threshold 0-180; 0 means PS default [0] */
		double bb[4];			/* Boundingbox arguments			*/
		PSL_LONG ix, iy;		/* Absolute coordinates of last point		*/
		double p_width;			/* Paper width in points, set in PSL_beginplot();	*/
		double p_height;		/* Paper height in points, set in PSL_beginplot();	*/
		PSL_LONG length;		/* Image row output byte counter		*/
		PSL_LONG n_userimages;		/* Number of specified custom patterns		*/
		double dpu;			/* PS dots per unit.  Must be set through PSL_beginplot();		*/
		double dpp;			/* PS dots per point.  Must be set through PSL_beginplot();		*/
		double x2ix;			/* Scales user x to PS dots		*/
		double y2iy;			/* Scales user y to PS dots		*/
		double p2u;			/* Scales dimensions in points (e.g., fonts, linewidths) to user units (e.g. inch)		*/
		PSL_LONG x0, y0;		/* x,y PS offsets */
		double axis_limit[4];		/* The current xmin, xmax, ymin, ymax settings for axes */
		double axis_pos[2];		/* Lower left placement for axes */
		double axis_dim[2];		/* Lengths of axes */
		FILE *fp;			/* PS output file pointer. NULL = stdout	*/
		struct PSL_FONT {
			double height;		/* Height of A for unit fontsize */
			char *name;		/* Name of this font */
			PSL_LONG encoded;	/* TRUE if we never should reencode this font (e.g. symbols) */
						/* This is also changed to TRUE after we do reencode a font */
		} *font;	/* Pointer to array of font structures 		*/
		struct PSL_PATTERN {
			PSL_LONG nx, ny;
			PSL_LONG status, depth, dpi;
			double f_rgb[4], b_rgb[4];
		} pattern[PSL_N_PATTERNS*2];
	} internal;
};

struct imageinfo {
	int magic;		/* magic number */
	int width;		/* width (pixels) of image */
	int height;		/* height (pixels) of image */
	int depth;		/* depth (1, 8, or 24 bits) of pixel; 0 for EPS */
	int length;		/* length (bytes) of image */
	int type;		/* type of file; see RT_* below */
	int maptype;	/* type of colormap; see RMT_* below */
	int maplength;	/* length (bytes) of following map */
	int xorigin;	/* x-coordinate of origin (EPS only) */
	int yorigin;	/* y-coordinate of origin (EPS only) */
	/* color map follows for maplength bytes, followed by image */
};

#define	RAS_MAGIC	0x59a66a95	/* Magic number for Sun rasterfile */
#define EPS_MAGIC	0x25215053	/* Magic number for EPS file */
#define RT_OLD		0		/* Old-style, unencoded Sun rasterfile */
#define RT_STANDARD	1		/* Standard, unencoded Sun rasterfile */
#define RT_BYTE_ENCODED	2		/* Run-length-encoded Sun rasterfile */
#define RT_FORMAT_RGB	3		/* [X]RGB instead of [X]BGR Sun rasterfile */
#define RT_EPS		4		/* Encapsulated PostScript format */
#define RMT_NONE	0		/* maplength is expected to be 0 */
#define RMT_EQUAL_RGB	1		/* red[maplength/3], green[], blue[] follow */

/* Public functions */

EXTERN_MSC struct PSL_CTRL *New_PSL_Ctrl (char *session);
EXTERN_MSC PSL_LONG PSL_beginaxes (struct PSL_CTRL *P, double llx, double lly, double width, double height, double x0, double y0, double x1, double y1);
EXTERN_MSC PSL_LONG PSL_beginclipping (struct PSL_CTRL *P, double *x, double *y, PSL_LONG n, double rgb[], PSL_LONG flag);
EXTERN_MSC PSL_LONG PSL_beginplot (struct PSL_CTRL *P, FILE *fp, PSL_LONG orientation, PSL_LONG overlay, PSL_LONG colormode, PSL_LONG absolute, double xyorigin[], double page_size[], struct EPS *eps);
EXTERN_MSC PSL_LONG PSL_beginsession (struct PSL_CTRL *PSL);
EXTERN_MSC PSL_LONG PSL_endaxes (struct PSL_CTRL *PSL);
EXTERN_MSC PSL_LONG PSL_endclipping (struct PSL_CTRL *P, PSL_LONG mode);
EXTERN_MSC PSL_LONG PSL_endplot (struct PSL_CTRL *P, PSL_LONG lastpage);
EXTERN_MSC PSL_LONG PSL_endsession (struct PSL_CTRL *P);
EXTERN_MSC PSL_LONG PSL_plotarc (struct PSL_CTRL *P, double x, double y, double radius, double az1, double az2, PSL_LONG type);
EXTERN_MSC PSL_LONG PSL_plotaxis (struct PSL_CTRL *P, double annotation_int, char *label, double annotfontsize, PSL_LONG side);
EXTERN_MSC PSL_LONG PSL_plotbitimage (struct PSL_CTRL *P, double x, double y, double xsize, double ysize, PSL_LONG justify, unsigned char *buffer, PSL_LONG nx, PSL_LONG ny, double f_rgb[], double b_rgb[]);
EXTERN_MSC PSL_LONG PSL_plotcolorimage (struct PSL_CTRL *P, double x, double y, double xsize, double ysize, PSL_LONG justify, unsigned char *buffer, PSL_LONG nx, PSL_LONG ny, PSL_LONG nbits);
EXTERN_MSC PSL_LONG PSL_plotepsimage (struct PSL_CTRL *P, double x, double y, double xsize, double ysize, PSL_LONG justify, unsigned char *buffer, PSL_LONG size, PSL_LONG nx, PSL_LONG ny, PSL_LONG ox, PSL_LONG oy);
EXTERN_MSC PSL_LONG PSL_plotline (struct PSL_CTRL *P, double *x, double *y, PSL_LONG n, PSL_LONG type);
EXTERN_MSC PSL_LONG PSL_plotparagraph (struct PSL_CTRL *P, double x, double y, double fontsize, char *paragraph, double angle, PSL_LONG justify);
EXTERN_MSC PSL_LONG PSL_plotparagraphbox (struct PSL_CTRL *P, double x, double y, double fontsize, char *paragraph, double angle, PSL_LONG justify, double offset[], PSL_LONG mode);
EXTERN_MSC PSL_LONG PSL_plotpoint (struct PSL_CTRL *P, double x, double y, PSL_LONG pen);
EXTERN_MSC PSL_LONG PSL_plotbox (struct PSL_CTRL *P, double x0, double y0, double x1, double y1);
EXTERN_MSC PSL_LONG PSL_plotpolygon (struct PSL_CTRL *P, double *x, double *y, PSL_LONG n);
EXTERN_MSC PSL_LONG PSL_plotsegment (struct PSL_CTRL *P, double x0, double y0, double x1, double y1);
EXTERN_MSC PSL_LONG PSL_plotsymbol (struct PSL_CTRL *P, double x, double y, double param[], PSL_LONG symbol);
EXTERN_MSC PSL_LONG PSL_plottext (struct PSL_CTRL *P, double x, double y, double fontsize, char *text, double angle, PSL_LONG justify, PSL_LONG mode);
EXTERN_MSC PSL_LONG PSL_plottextbox (struct PSL_CTRL *P, double x, double y, double fontsize, char *text, double angle, PSL_LONG justify, double offset[], PSL_LONG mode);
EXTERN_MSC PSL_LONG PSL_plottextclip (struct PSL_CTRL *P, double x[], double y[], PSL_LONG m, double fontsize, char *label[], double angle[], PSL_LONG justify, double offset[], PSL_LONG mode);
EXTERN_MSC PSL_LONG PSL_plottextpath (struct PSL_CTRL *P, double x[], double y[], PSL_LONG n, PSL_LONG node[], double fontsize, char *label[], PSL_LONG m, double angle[], PSL_LONG justify, double offset[], PSL_LONG mode);
EXTERN_MSC PSL_LONG PSL_loadimage (struct PSL_CTRL *P, char *file, struct imageinfo *header, unsigned char **image);
EXTERN_MSC PSL_LONG PSL_setcolor (struct PSL_CTRL *P, double rgb[], PSL_LONG mode);
EXTERN_MSC PSL_LONG PSL_setdefaults (struct PSL_CTRL *P, double dpi, double xyscales[], double page_rgb[]);
EXTERN_MSC PSL_LONG PSL_setdash (struct PSL_CTRL *P, char *pattern, double offset);
EXTERN_MSC PSL_LONG PSL_setfill (struct PSL_CTRL *P, double rgb[], PSL_LONG outline);
EXTERN_MSC PSL_LONG PSL_setfont (struct PSL_CTRL *P, PSL_LONG font_no);
EXTERN_MSC PSL_LONG PSL_setformat (struct PSL_CTRL *P, PSL_LONG n_decimals);
EXTERN_MSC PSL_LONG PSL_setlinecap (struct PSL_CTRL *P, PSL_LONG cap);
EXTERN_MSC PSL_LONG PSL_setlinejoin (struct PSL_CTRL *P, PSL_LONG join);
EXTERN_MSC PSL_LONG PSL_setlinewidth (struct PSL_CTRL *P, double linewidth);
EXTERN_MSC PSL_LONG PSL_setmiterlimit (struct PSL_CTRL *P, PSL_LONG limit);
EXTERN_MSC PSL_LONG PSL_setorigin (struct PSL_CTRL *P, double x, double y, double angle, PSL_LONG mode);
EXTERN_MSC PSL_LONG PSL_setparagraph (struct PSL_CTRL *P, double line_space, double par_width, PSL_LONG par_just);
EXTERN_MSC PSL_LONG PSL_setpattern (struct PSL_CTRL *P, PSL_LONG image_no, char *imagefile, PSL_LONG image_dpi, double f_rgb[], double b_rgb[]);
EXTERN_MSC PSL_LONG PSL_settransparencymode (struct PSL_CTRL *PSL, char *mode);
EXTERN_MSC PSL_LONG PSL_definteger (struct PSL_CTRL *P, char *param, PSL_LONG value);
EXTERN_MSC PSL_LONG PSL_defpen (struct PSL_CTRL *P, char *param, double width, char *style, double offset, double rgb[]);
EXTERN_MSC PSL_LONG PSL_defpoints (struct PSL_CTRL *P, char *param, double fontsize);
EXTERN_MSC PSL_LONG PSL_defcolor (struct PSL_CTRL *P, char *param, double rgb[]);
EXTERN_MSC PSL_LONG PSL_deftextdim (struct PSL_CTRL *P, char *dim, double fontsize, char *text);
EXTERN_MSC PSL_LONG PSL_defunits (struct PSL_CTRL *P, char *param, double value);
EXTERN_MSC unsigned char *psl_gray_encode (struct PSL_CTRL *PSL, PSL_LONG *nbytes, unsigned char *input);

/* Other deep level routines that could be useful */
EXTERN_MSC PSL_LONG psl_ix (struct PSL_CTRL *P, double value);
EXTERN_MSC PSL_LONG psl_iy (struct PSL_CTRL *P, double value);
EXTERN_MSC PSL_LONG psl_iz (struct PSL_CTRL *P, double value);
EXTERN_MSC PSL_LONG psl_ip (struct PSL_CTRL *P, double value);

/* Used indirectly by macro PSL_free and FORTRAN wrapper PSL_free_ . */
EXTERN_MSC PSL_LONG PSL_free_nonmacro (struct PSL_CTRL *P, void **addr);

/* Definition for printing a message. When DEBUG is on, also print source file and line number.
 * Use this for various progress statements, debugging to see certain variables, and even fatal
 * error messages. */
#if defined (WIN32) || defined (__MINGW32__)
/* Due to the DLL boundary cross problem on Windows the next macros are implemented as functions
   in pslib.c */
EXTERN_MSC int PSL_command (struct PSL_CTRL *C, char *format, ...);
EXTERN_MSC int PSL_initerr (struct PSL_CTRL *C, char *format, ...);
EXTERN_MSC FILE *PSL_fopen (char *file, char *mode);
#else
/* From FORTRAN there is PSL_command_ that only accepts one text argument */
#define PSL_initerr(C,...) fprintf (C->init.err, __VA_ARGS__)
#define PSL_command(C,...) fprintf (C->internal.fp, __VA_ARGS__)
#define PSL_fopen fopen
#endif

#ifdef DEBUG
#define PSL_message(C,level,...) ((level) <= C->internal.verbose ? PSL_initerr (C, "PSL:%s:%d: ", __FILE__, __LINE__) + PSL_initerr (C, __VA_ARGS__) : 0)
#else
#define PSL_message(C,level,...) ((level) <= C->internal.verbose ? PSL_initerr (C, "PSL: ") + PSL_initerr (C, __VA_ARGS__) : 0)
#endif

#define PSL_comment(C,...) (C->internal.comments ? PSL_command (C, "%%\n%% ") + PSL_command (C, __VA_ARGS__) + PSL_command (C, "%%\n") : 0)
#define PSL_free(C,ptr) PSL_free_nonmacro (C,(void**)&ptr)					/* Easier macro for PSL_free */

#ifdef __cplusplus
}
#endif

#endif /* _PSLIB_H */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:53:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/07 20:45:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H

# include <stddef.h>

static char const	*g_flag[] = {
	/* [ CURSOR MOTION ] */
	"os",	/* The terminal can overstrike */
	"eo",	/* Outputting a space erases a character position */
	"gn",	/* The terminal type is a generic type */
	"hc",	/* This is a hardcopy terminal */
	"hz",	/* '~' character cannot be output in this terminal */
	"xb",	/* This is a Superbee terminal, unable to transmit Ctrl-C and ESC */
	"bw",	/* The cap "le" may be used
				in first column to move to the last column of the upper line */
	"nc",	/* OBSOLETE Terminal does not support ASCII carriage return */
	"xt",	/* OBSOLETE ASCII tab character may not be used for cursor motion */
	"bc",	/* OBSOLETE Same as cap "le" */
	"bs",	/* OBSOLETE The backspace character may be used
				to move the cursor left */
	/* [ WRAPPING ] */
	"am",	/* Writing a character in the last column causes the cursor
				to wrap to the beginning of the next line */
	"xn",	/* The cursor wraps in a strange way */
	"LP",	/* It is safe to write in the last column of the last line
				without worrying about undesired scrolling */
	/* [ SCROLLING ] */
	"ns",	/* Terminal doesn't normally scroll
				for ordinary sequential output */
	"da",	/* Lines scrolled up off the top of the screen may be back
				on scrolling down */
	"db",	/* Lines scrolled down off the bottom of the screen may be back
				on scrolling up */
	/* [ INSERT/DELETE CHARACTER ] */
	"mi",	/* It is safe to move the cursor while in insert mode
				and assume the terminal remains in insert mode */
	"in",	/* The terminal distinguish between
				character positions in which space characters have been output
				and
				positions which have been cleared */
	NULL
};

static char const	*g_str_cmd[] = {
	/* [ CURSOR MOTION ] */
	"rp",	/* Output a character `c` repeated `n` times */
	"cm",	/* Position the cursor at line `l` and column `c` absolutely */
	"ho",	/* Move the cursor to the upper left corner */
	"ll",	/* Move the cursor to the lower left corner */
	"cr",	/* Move the cursor at the beginning of the line */
	"up",	/* Move the cursor up 1 line */
	"do",	/* Move the cursor down 1 line */
	"le",	/* Move the cursor left 1 column */
	"nd",	/* Move the cursor right 1 column */
	"nw",	/* Move the cursor at the beginning of the next line */
	"UP",	/* Move the cursor up `n` lines */
	"DO",	/* Move the cursor down `n` lines */
	"LE",	/* Move the cursor left `n` columns */
	"RI",	/* Move the cursor right `n` columns */
	"CM",	/* Position the cursor at line `l` and column `c` relatively */
	"ch",	/* Position the cursor at column `c` in the same line */
	"cv",	/* Position the cursor at line `l` in the same column */
	"sc",	/* Save the cursor position */
	"rc",	/* Position the cursor to the last savec position */
	"ff",	/* Advance to the next page */
	"ta",	/* Move the cursor right to the next hardware tab stop column */
	"bt",	/* Move the cursor left to the previous hardware tab stop column */
	"nl",	/* OBSOLETE Move the cursor down, or scroll if in the last line */
	/* [ SCROLLING ] */
	"sf",	/* Scroll the screen 1 line up */
	"sr",	/* Scroll the screen 1 line down */
	"SF",	/* Scroll the screen `n` lines up */
	"SR",	/* Scroll the screen `n` lines down */
	"cs",	/* Set the scroll region, giving parameters `start` and `end` */
	/* [ WINDOW ] */
	"wi",	/* Set the terminal output screen window passing the four parameters
				`first line to include in the window`
				`last line to include in the window`
				`first column to include in the window`
				`last column to include in the window` */
	/* [ CLEARING PARTS OF THE SCREEN ] */
	"cl",	/* Clear the entire screen
				and position the cursor at the upper left corner */
	"cd",	/* Clear the line the cursor is on, and all the lines below,
				down to the bottom of the screen */
	"ce",	/* Clear from the cursor position to the end of the current line */
	"ec",	/* Clear `n` characters from the cursor position */
	/* [ INSERT/DELETE LINE ] */
	"al",	/* Insert 1 blank line before the line the cursor is on */
	"dl",	/* Delete the line the cursor is on */
	"AL",	/* Insert `n` blank lines before the line the cursor is on */
	"DL",	/* Delete `n` lines from the line the cursor is on */
	/* [ INSERT/DELETE CHARACTER ] */
	"im",	/* Enter insert mode */
	"ei",	/* Leave insert mode */
	"ic",	/* Insert 1 character position at the cursor */
	"ip",	/* Output following an inserted graphic character in insert mode */
	"IC",	/* Insert `n` characters positions at and after the cursor */
	"dc",	/* Delete 1 character position at the cursor */
	"DC",	/* Delete `n` character starting at the cursor */
	"dm",	/* Enter delete mode */
	"ed",	/* Leave delete mode */
	/* [ STANDOUT AND APPEARANCE MODES ] */
	NULL
};

#endif

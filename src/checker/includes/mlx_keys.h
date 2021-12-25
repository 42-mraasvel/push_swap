/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_keys.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/26 11:39:49 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/05/12 11:18:00 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYS_H
# define MLX_KEYS_H

# ifdef __APPLE__

/*
** Keyboard LETTERS
*/

#  define K_A 0
#  define K_B 11
#  define K_C 8
#  define K_D 2
#  define K_E 14
#  define K_F 3
#  define K_G 5
#  define K_H 4
#  define K_I 34
#  define K_J 38
#  define K_K 40
#  define K_L 37
#  define K_M 46
#  define K_N 45
#  define K_O 31
#  define K_P 35
#  define K_Q 12
#  define K_R 15
#  define K_S 1
#  define K_T 17
#  define K_U 32
#  define K_V 9
#  define K_W 13
#  define K_X 7
#  define K_Y 16
#  define K_Z 6

/*
** Keyboard ARROWS
*/

#  define K_AR_L 123
#  define K_AR_R 124
#  define K_AR_U 126
#  define K_AR_D 125

/*
** Keyboard NUMPAD
*/

#  define K_NP_DIV 75
#  define K_NP_MUL 67
#  define K_NP_MIN 78
#  define K_NP_PLU 69
#  define K_NP_1	83
#  define K_NP_2	84
#  define K_NP_3	85
#  define K_NP_4	86
#  define K_NP_5	87
#  define K_NP_6	88
#  define K_NP_7	89
#  define K_NP_8	91
#  define K_NP_9	92

/*
** Keyboard MISC
*/

#  define K_SP 49
#  define K_ESC 53
#  define K_TAB 48
#  define K_ENTER 36
#  define K_ENTER2 76

/*
** Mouse
*/

#  define M_CLK_L 1
#  define M_CLK_R 3
#  define M_CLK_M 2
#  define M_SCR_U 4
#  define M_SCR_D 5

# else

/*
** Keyboard LETTERS
*/

#  define K_A 97
#  define K_B 98
#  define K_C 99
#  define K_D 100
#  define K_E 101
#  define K_F 102
#  define K_G 103
#  define K_H 104
#  define K_I 105
#  define K_J 106
#  define K_K 107
#  define K_L 108
#  define K_M 109
#  define K_N 110
#  define K_O 111
#  define K_P 112
#  define K_Q 113
#  define K_R 114
#  define K_S 115
#  define K_T 116
#  define K_U 117
#  define K_V 118
#  define K_W 119
#  define K_X 120
#  define K_Y 121
#  define K_Z 122

/*
** Keyboard ARROWS
*/

#  define K_AR_L 65361
#  define K_AR_R 65363
#  define K_AR_U 65362
#  define K_AR_D 65364

/*
** Keyboard NUMPAD
*/

#  define K_NP_DIV 65455
#  define K_NP_MUL 65450
#  define K_NP_MIN 65453
#  define K_NP_PLU 65451

/*
** Keyboard MISC
*/

#  define K_SP 32
#  define K_ESC 65307
#  define K_ENTER 65293

/*
** Mouse
*/

#  define M_CLK_L 1
#  define M_CLK_R 3
#  define M_CLK_M 2
#  define M_SCR_U 4
#  define M_SCR_D 5

# endif

#endif

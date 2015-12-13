/*
** mlcap.h for mlcap in /home/cochoy_j/rendu/rush/grimly/part3/lib/mlcap
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sat Apr 25 09:30:29 2009 jeremy cochoy
** Last update Sun May 17 11:06:10 2009 jeremy cochoy
*/

#ifndef MLC_H_
# define MLC_H_

# define	KEY_UNKNOW	0
# define	KEY_UP		1
# define	KEY_DOWN	2
# define	KEY_LEFT	3
# define	KEY_RIGHT	4
# define	KEY_ESC		5
# define	KEY_CTRLA	6
# define	KEY_CTRLE	7
# define	KEY_CTRLW	8
# define	KEY_CTRLS	9

/*
** Colors
*/
# define	CLR_BLACK		"\033[0;0;30m"
# define	CLR_RED			"\033[0;0;31m"
# define	CLR_GREEN		"\033[0;0;32m"
# define	CLR_ORANGE		"\033[0;0;33m"
# define	CLR_BLUE		"\033[0;0;34m"
# define	CLR_VIOLET		"\033[0;0;35m"
# define	CLR_CYAN		"\033[0;0;36m"
# define	CLR_LIGHTGRAY		"\033[0;0;37m"

# define	CLR_GRAY		"\033[1;0;32m"
# define	CLR_PINK		"\033[1;0;31m"
# define	CLR_LIGHTGREEN		"\033[1;0;32m"
# define	CLR_YELLOW		"\033[1;0;33m"
# define	CLR_LIGHTBLUE		"\033[1;0;34m"
# define	CLR_LIGHTVIOLET		"\033[1;0;35m"
# define	CLR_LIGHTCYAN		"\033[1;0;36m"
# define	CLR_WHITE		"\033[1;0;37m"

# define	CLR__BLACK		"\033[0;4;30m"
# define	CLR__RED		"\033[0;4;31m"
# define	CLR__GREEN		"\033[0;4;32m"
# define	CLR__ORANGE		"\033[0;4;33m"
# define	CLR__BLUE		"\033[0;4;34m"
# define	CLR__VIOLET		"\033[0;4;35m"
# define	CLR__CYAN		"\033[0;4;36m"
# define	CLR__LIGHTGRAY		"\033[0;4;37m"

# define	CLR__GRAY		"\033[1;4;32m"
# define	CLR__PINK		"\033[1;4;31m"
# define	CLR__LIGHTGREEN		"\033[1;4;32m"
# define	CLR__YELLOW		"\033[1;4;33m"
# define	CLR__LIGHTBLUE		"\033[1;4;34m"
# define	CLR__LIGHTVIOLET	"\033[1;4;35m"
# define	CLR__LIGHTCYAN		"\033[1;4;36m"
# define	CLR__WHITE		"\033[1;4;37m"

# define	CLR_NONE		"\033[0;0;0m"

/*
*******************************************************************
** MLC functions : Create a rander, push data, ad show it..       *
**                 Can give many informations about screen etc... *
*******************************************************************
*/

/*
** Loop hook
** @return 1 when it's time to stop, otherwise 0
*/
typedef	int (*p_loop_hook)(void *param);

/*
** Key Hook
*/
typedef	void (*p_key_hook)(char *str, void *param);

/*
** Resize hook
*/
typedef	void (*p_resize_hook)(int w, int h, void *param);

/*
** Init mlcap
*/
void	*mlc_init(void);

/*
** Close mlcap
*/
void	mlc_close(void);

/*
** Hook loop
*/
void	mlc_loop_hook(p_loop_hook hook, void *param);

/*
** Hook key
*/
void	mlc_key_hook(p_key_hook hook, void *param);

/*
** Resize hook
*/
void	mlc_resize_hook(p_resize_hook hook, void *param);

/*
** Get position (from buffer)
*/
void	mlc_getpos(int *y, int *x);

/*
** Set position (in buffer)
*/
void	mlc_setpos(int y, int x);

/*
** Move cursor and pos at (x, y)
*/
void	mlc_move(int x, int y);

/*
** Show cursor
*/
void	mlc_cur_show(void);

/*
** Hide cursor
*/
void	mlc_cur_hide(void);

/*
** Clear screen
*/
void	mlc_clear(void);

/*
** Put a char (in buffer) at current pos
*/
void	mlc_putchar(char c);

/*
** Put a string (in buffer) at current pos
*/
void	mlc_putstr(char *str);

/*
** Get char (from buffer) at current pos
*/
char	mlc_getchar(void);

/*
** Put color at current pos
*/
void	mlc_putcolor(char *color);

/*
** Get color from current pos
*/
char	*mlc_getcolor(void);

/*
** Write a string (without buffer)
*/
void	mlc_putstr(char *str);

/*
** Loop until your callback return 1
*/
void	mlc_loop(void);

/*
** Width
*/
int	mlc_width(void);

/*
** Width
*/
int	mlc_height(void);

/*
** Return key code
*/
int	mlc_keycode(char *str);

/*
** Display screen
*/
void	mlc_show(void);

/*
*******************************************************************
** PICTURES : You can create ascii pictures and blit it on screen.*
**            Use picture is a good way to prevent display bugs.  *
*******************************************************************
*/

/*
** Create an empty picture filled with c and color
** @param color 0 and the picture will let the screen color (trensparency)
** @param c 0 and the picture will be trensparent
** @param w Width
** @param h Height
*/
void	*mlc_create_picture(int w, int h, char c, char *color);

/*
** Delete a picture
*/
void	mlc_delete_picture(void *img);

/*
** Replace by c and color in the whole picture
*/
void	mlc_fill_picture(void *img, char c, char *color);

/*
** Blit a picture on screen
*/
void	mlc_blit_picture(void *img, int x, int y);

/*
** Get a picure width
*/
void	mlc_picture_width(void *img);

/*
** Get a picure height
*/
void	mlc_picture_height(void *img);

/*
** Get a char[y][x] (h*w) with picture data
** (you can put your own data)
*/
char	**mlc_picture_data(void *img);

/*
** Get a char*[y][x] (h*w) with color strings
** You can put a color with tab[y][x] = CLR_BLUE;
** Or remove color with tab[y][x] = 0;
*/
char	***mlc_picture_color(void *img);

/*
** Save a picture into a file
*/
int	mlc_picture_save(void *img, char *filename);

/*
** Load a picture from a file
*/
void	*mlc_picture_load(char *filename);

/*
** Create a picture from screen
*/
void	*mlc_capture(void);

#endif /* !MLC_H_ */

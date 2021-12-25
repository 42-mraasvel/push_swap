/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/24 19:27:20 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/20 12:39:09 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strdup(const char *s);
void				*ft_calloc(size_t nmemb, size_t size);

/*
** part 2
*/

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Bonus Part
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}	t_list;

/*
** The bonus functions
*/

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *nw);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *nw);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void*));
t_list				*ft_lstmap(t_list *lst,
						void *(*f)(void*), void (*del)(void*));

/*
** Additional functions
*/

ssize_t				ft_putnofc(size_t n, unsigned char c);
ssize_t				ft_putstr_p(char *str, ssize_t precision);
void				ft_free(int cnt, ...);
int					ft_isspace(int c);
int					put_binary_representation_of_area(void *area, size_t n);
int					put_hex_representation_of_area(void *area, size_t n);
int					ft_putstr(char *str);
char				*ft_join_n_strings(int cnt, ...);
char				**ft_split_set(const char *src, const char *set);
char				**ft_split_token(const char *src, const char *token);
size_t				ft_count_strings(char **strings);
char				*ft_strstr(const char *haystack, const char *needle);
void				ft_free_split(char **strings);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_swap_ptr(void *a, void *b);
void				ft_strlowcase(char *str);
void				ft_strupcase(char *str);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strchri(const char *s, int c);

/*
** get_next_line libft version.
*/

int					ft_getline(int fd, char **line);

/*
** Number functions
*/

int					ft_unumlen_base(unsigned long long nbr, int base);
int					ft_numlen_base(long long nbr, int base);
int					ft_putll(long long nbr, int precision);
int					ft_putllu(unsigned long long nbr, int precision);
int					ft_putllu_base(unsigned long long nbr,
						int base, int precision, int upcase);
char				*ft_llutoa(unsigned long long nbr, int min_len);
unsigned long long	ft_atoull(char *str);
double				ft_atof(char *str);
unsigned long long	ft_atoull_base(const char *str, int base);
long long int		ft_strtoll(const char *nptr);

/*
** math functions
*/

double				ft_pow(double x, double y);
int					ft_numlen_dbl(double num);
int					ft_dbl_tenthpow(double nbr);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
double				ft_fmax(double a, double b);
double				ft_fmin(double a, double b);
int					ft_abs(int a);
double				ft_fabs(double x);
long long			ft_absll(long long l);

int					ft_inrange(int num, int min, int max);
int					ft_inrangef(float num, float min, float max);
int					ft_inrangell(long long num, long long min, long long max);

#endif

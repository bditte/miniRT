/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:30:09 by bditte            #+#    #+#             */
/*   Updated: 2020/11/21 17:51:15 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
void			ft_putendl_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(const char *s, int n, ...);
void			ft_putnbr_fd(int n, int fd);
int				ft_atoi(const char *str);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr
					(const char *haystack, const char *needle, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *src);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_putstr(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strdup(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap
					(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif

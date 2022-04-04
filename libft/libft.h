/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaham <jaham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:06:49 by jaham             #+#    #+#             */
/*   Updated: 2022/04/04 14:19:17 by jaham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int		ft_isalpha(int c);
int		ft_isnum(int c);
int		ft_isnumstr(const char *str);
int		ft_atoi(const char *str);
ssize_t	ft_putstr_fd(const char *str, int fd);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *str, size_t start, size_t len);
void	ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *str, const char *sep);
char	*ft_strchr(const char *str, int c);
char	*ft_getcwd(char *buf, size_t size);
void	free_c_dptr(char ***ptr);
void	*ft_malloc(size_t size, size_t n);
pid_t	ft_fork(void);
void	ft_free(void **ptr);
void	perror_exit(const char *str, unsigned int exit_status);
char	*get_next_line(int fd);
int		ft_waitpid(pid_t pid, int *status, int op);
int		ft_wifexited(int status);
int		ft_wexitstatus(int status);
int		ft_wifsignaled(int status);
int		ft_wtermsig(int status);
int		ft_wifstopped(int status);
int		ft_pipe(int pipefd[2]);
int		ft_dup2(int fd1, int fd2);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_close(int fd);
void	exit_with_msg(char *s1, char *s2, int status);
int		ft_dup(int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_isspace(int c);
size_t	ft_min(size_t n1, size_t n2);
size_t	ft_max(size_t n1, size_t n2);

#endif
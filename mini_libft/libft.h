/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderraj <aderraj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:27:41 by aderraj           #+#    #+#             */
/*   Updated: 2024/04/27 23:44:08 by aderraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	ft_putstr_fd(char *s, int fd);

int		ft_safe_atoi(const char *str, char **args);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c, int *len);

size_t	ft_strlen(const char *s);

#endif

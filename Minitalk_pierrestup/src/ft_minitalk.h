/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremoretton <pierremoretton@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:10:20 by pierremoret       #+#    #+#             */
/*   Updated: 2022/08/01 01:32:57 by pierremoret      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

void	putstr_fd(char *str, int fd);
void	putnbr_fd(int nb, int fd);
int		mt_atoi(const char *nptr);
int		pid_check(char *str);

#endif

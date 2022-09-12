/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierremoretton <pierremoretton@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:10:20 by pierremoret       #+#    #+#             */
/*   Updated: 2022/08/02 13:21:54 by pierremoret      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

void	putstr_fd(char *str, int fd);
void	putnbr_fd(int nb, int fd);
int		mt_atoi(const char *nptr);
int		pid_check(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:44:23 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/09/27 16:44:25 by ludovictrom      ###   ########.fr       */
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

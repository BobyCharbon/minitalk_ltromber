/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludovictrombert <ludovictrombert@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:43:59 by ludovictrom       #+#    #+#             */
/*   Updated: 2022/09/27 16:44:02 by ludovictrom      ###   ########.fr       */
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

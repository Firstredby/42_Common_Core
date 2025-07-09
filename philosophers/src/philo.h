/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishchyro <ishchyro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:18:06 by ishchyro          #+#    #+#             */
/*   Updated: 2025/07/09 14:49:40 by ishchyro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>

//error messages
# define WRONG_INPUT 22
# define NAN 74
# define MALLOC 12
# define TIME 5
# define NN 13
# define ZERO 0

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					index;
	int					eaten;//how much times
	pthread_t			thread;
	size_t				lte; //last time eaten
	pthread_mutex_t		fork;
	t_data				*data;
}	t_philo;

typedef struct s_data
{
	int				nop; //number of philos
	int				dead;
	int				nte; //ntimes each eaten
	int				all_ready;
	size_t			tts; //time to sleep
	size_t			tte; //time to eat
	size_t			ttd; //time to die
	size_t			begin;
	size_t			finish;
	pthread_mutex_t	status;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	print;
	t_philo			*philo;
}	t_data;

//initialisation
int		philo_init(t_data *data);
int		data_init(t_data *data);
int		philo_create(t_data *data);
//main processes
void	*routine(void *data);
bool	all_philos_eat(t_data *data);
void	philo_action(t_philo *philo, int action);
bool	is_dead(t_philo *philo);
void	philo_action(t_philo *philo, int action);
//utils
size_t	curr_time(void);
bool	is_num(char *str);
void	philo_free(t_philo *philo, size_t philos);
long	ft_philo_atol(char *str);
void	fail_free(t_philo *philo, size_t philos, size_t mutexes);
void	mutex_free(t_data *data);
bool	value_validation(char **params);
void	ft_usleep(t_philo *philo, size_t time);
int		all_ready(t_philo *philo);
int		error_cases(int case_id);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:24:08 by psim              #+#    #+#             */
/*   Updated: 2018/11/30 12:06:53 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>

typedef struct	s_ttrm
{
	char tab[4][4];
}				t_ttrm;

/*
** Retourne un tableau de pointeur de tetrominos termine par NULL
** ou NULL si erreur.
*/
t_ttrm			**fd_to_ttrm_tab(int fd);

/*
** Retourne 1 en cas de succes et 0 en cas d'echec, alloue
** et remplie le tetrominos passe em parametre avec
** le prochain tetrominos contenu dans le fd.
*/
int				fill_ttrm(int fd, t_ttrm **new_ttrm);

/*
** Normalise le tetrominos en deplacant ses blocs le plus en haut a gauche
** possible tout en conservant sa forme.
*/
void			normalize_ttrm(t_ttrm *ttrm);

/*
** Retourne 1 si les blocs du tetrominos representent un tetrominos valide,
** 0 sinon.
** Le tetrominos ne doit contenir que des caracteres '.' et '#'.
*/
int				check_ttrm_block(t_ttrm *ttrm);

/*
** Free chaque tetrominos d'un tableau termine par NULL individuellement
** puis free le tableau en lui-meme.
*/
void			free_ttrm_tab(t_ttrm **ttrm_tab);

#endif

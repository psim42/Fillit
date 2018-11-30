/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:24:08 by psim              #+#    #+#             */
/*   Updated: 2018/11/30 13:41:28 by fwerner          ###   ########.fr       */
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
** Alloue et remplie le tetrominos passe em parametre avec
** le prochain tetrominos contenu dans le fd.
** Retourne 1 ou 0 si le tetrominos a pu etre lu et est valide, 1 si le fd
** contient encore des caracteres, 0 sinon. Retourne -1 en cas d'erreur.
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

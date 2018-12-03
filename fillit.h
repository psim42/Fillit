/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 14:24:08 by psim              #+#    #+#             */
/*   Updated: 2018/12/03 13:59:08 by psim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>

typedef struct	s_ttrm
{
	char tab[4][4];
}				t_ttrm;

typedef struct	s_map
{
	char	**tab;
	int		size;
}				t_map;

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

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

/*
** Essaye d'ajouter le tetrominos a la map a la position x, y. Si l'ajout est
** reussi retourne 1, sinon retourne 0.
*/
int				insert_ttrm(t_map *map, t_ttrm *ttrm, int x, int y);
//verifier uniquement le char '.'

/*
** Supprime le tetrominos dans la map a la position donnee.
*/
void			remove_ttrm(t_map *map, t_ttrm *ttrm, int x, int y);

/*
** Free le tableau de chaine de charactere de la map.
*/
void			free_map(t_map *map);

/*
** Affiche la map passee en parametre.
*/
void			print_map(t_map *map);

/*
** Retourne un pointeur sur t_map representant la resolution du fillit avec les
** tetrominos donnes ou retourne NULL en cas d'erreur.
*/
t_map			*resolve_fillit(t_ttrm **ttrm_tab);

/*
** Free le contenu de la map (tableau de string uniquement) et met sa size a 0.
** Si un element du tableau vaut NULL le free s'arrete.
*/
void			free_map_content(t_map *map);

/*
** Change la taille de la map passee en parametre.
*/
int				resize_map(t_map *map, int new_size);

#endif

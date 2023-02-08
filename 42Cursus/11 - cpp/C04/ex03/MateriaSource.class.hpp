/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <ddelladi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:40:08 by ddelladi          #+#    #+#             */
/*   Updated: 2022/10/09 14:37:19 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP
# include "IMateriaSource.class.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_inv[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		MateriaSource&	operator=(MateriaSource const & rhs);
		~MateriaSource();
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);	
};

#endif

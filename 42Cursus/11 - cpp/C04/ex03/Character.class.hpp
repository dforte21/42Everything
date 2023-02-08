/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <ddelladi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:44:41 by ddelladi          #+#    #+#             */
/*   Updated: 2022/10/08 21:29:32 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP
# include "ICharacter.class.hpp"
# include "AMateria.class.hpp"

class Character : public ICharacter
{
	private:
		AMateria*	_inv[4];
		std::string	_name;
	public:
		Character();
		Character(std::string const & name);
		Character(Character const & src);
		Character&	operator=(Character const & rhs);
		~Character();
		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif

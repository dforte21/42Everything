#ifndef	PFDS_HPP
# define PFDS_HPP

#include <cstdlib>
#include <poll.h>

class Pfds {
	public:
		Pfds(int fd);
		~Pfds();

		void			addToPfds(int new_fd);
		void			delFromPfds(int i);

		struct pollfd	*getSocketArr() const;
		size_t			getSize() const;
		size_t			getCount() const;

	private:
		struct pollfd	*_socketArr;
		size_t			_size;
		size_t			_count;
};

#endif
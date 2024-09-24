#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>
# include <iostream>
# include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		typedef typename Container::iterator iterator;

		typename Container::iterator begin(void)
		{
			return (this->c.begin());
		}
		typename Container::iterator end(void)
		{
			return (this->c.end());
		}
		// iterator begin(void)
		// {
		// 	return (this->c.begin());
		// }
		// iterator end(void)
		// {
		// 	return (this->c.end());
		// }
};


#endif

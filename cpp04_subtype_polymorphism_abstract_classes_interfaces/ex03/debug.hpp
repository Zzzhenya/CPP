#ifndef DEBUG_HPP
# define DEBUG_HPP

# include <iostream>

# ifdef _DEBUG
# define debug(x) ((x))
# else
# define debug(x)
# endif

#endif
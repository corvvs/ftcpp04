#ifndef CPP04_EX02_BRAIN_HPP_
# define CPP04_EX02_BRAIN_HPP_

# include <iostream>
# include <sstream>
# include "Constants.hpp"

class Brain {
    public:
        Brain();
        Brain(std::string type);
        virtual ~Brain();
        Brain(const Brain &from);
        Brain& operator=(const Brain &rhs);
    
        const std::string*  getIdeas(void) const;
        void                showIdeas(void) const;

    private:
        static const std::size_t N = 100;
        std::string ideas[N];

};

#endif

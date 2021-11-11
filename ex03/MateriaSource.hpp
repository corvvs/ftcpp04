#ifndef CPP04_EX03_MATERIASOURCE_HPP_
# define CPP04_EX03_MATERIASOURCE_HPP_

# include <iostream>
# include "IMateriaSource.hpp"
# include "Constants.hpp"

class MateriaSource: public IMateriaSource {
    private:
        static const std::size_t    kMaxMateria = 4;
        AMateria    *materias[MateriaSource::kMaxMateria];

    public:
        MateriaSource();
        virtual ~MateriaSource();
        MateriaSource(const MateriaSource& from);
        MateriaSource&  operator=(const MateriaSource &rhs);

        void        learnMateria(AMateria* m);
        AMateria*   createMateria(std::string const & type);
};

#endif

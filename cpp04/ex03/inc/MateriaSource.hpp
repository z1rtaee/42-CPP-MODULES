#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &src);
        ~MateriaSource();

        MateriaSource   &operator=(const MateriaSource &obj);

        void    learnMateria(AMateria *obj);
        AMateria *createMateria(std::string const &type);

    private:
        AMateria *_memory[4];
};

#endif
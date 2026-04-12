#include <MateriaSource.hpp>
#include <Character.hpp>
#include <Ice.hpp>
#include <Cure.hpp>


int main() {    
    IMateriaSource* src = new MateriaSource();
    AMateria* tmpLearn = new Cure();
    src->learnMateria(tmpLearn);
    delete tmpLearn;
    tmpLearn = new Ice();
    src->learnMateria(tmpLearn);
    delete tmpLearn;

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);
    me->unequip(1);

    delete bob;
    delete me;
    delete src;
    return 0;
}
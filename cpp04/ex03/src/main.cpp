#include <MateriaSource.hpp>
#include <Character.hpp>
#include <Ice.hpp>
#include <Cure.hpp>

/*subject main
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}

*/

/*my main
*/
int main() {    
    std::cout << RESET << BOLD << "\n========== MATERIA ARENA ==========" << RESET << std::endl;
    
    std::cout << RESET << BOLD << "[Phase 1] Learning spells" << RESET << std::endl;

    IMateriaSource* src = new MateriaSource();
    AMateria* tmpLearn = new Cure();
    src->learnMateria(tmpLearn);
    tmpLearn = new Ice();
    src->learnMateria(tmpLearn);

    std::cout << RESET << BOLD << "\n[Phase 2]" << RESET << " Equipping hero" << std::endl;
    ICharacter* me = new Character("Robin Wood");
    AMateria* tmp;

    //tmp = AMateria("ice") -> abstract cannot instantiate so we use the MateriaSource to get them and create them
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    std::cout << RESET << BOLD << "\n[Phase 3]" << RESET<< " Spawning target" << std::endl;
    ICharacter* bob = new Character("Aoi Todo");

    std::cout << RESET << BOLD << "\n[Phase 4] " << RESET << "Combat actions" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);   

    std::cout << RESET << BOLD << "\n[Phase 5] " << RESET << "Dropping loot" << std::endl;
    me->unequip(0);
    me->unequip(1);
    
    std::cout << RESET << BOLD << "\n[Phase 6] "<< RESET << "Cleanup" << std::endl;
    delete bob;
    delete me;
    delete src;
    
    std::cout << RESET << BOLD << "========== END OF RUN ==========" << RESET << "\n" << std::endl;
    return 0;
}
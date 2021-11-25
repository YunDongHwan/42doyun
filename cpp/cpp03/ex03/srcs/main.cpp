#include "../includes/DiamondTrap.hpp"

int main()
{
    {
        DiamondTrap doyun;
    }
    std::cout << std::endl;
    {
    DiamondTrap james("JAMES");

    james.attack("peter");
    james.beRepaired(100);
    james.takeDamage(200);

    james.highFiveGuys();
    james.guardGate();

    james.whoAmI();
    }
    return (0);
}

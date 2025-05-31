/* Chernyackov Eugeny chernyackov.eugeny@yandex.ru
labwork2
*/

#include "../include/MiniWarrior.hpp"

MiniWarrior::MiniWarrior() : MiniPlayer("Воин", 100, 100) {
    addAbility(MiniAbility("Мощный удар", 30, 20));
    addAbility(MiniAbility("Щит", 0, 10));
}

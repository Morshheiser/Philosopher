
#include "philo_library.h"

void *routine_philo(int philo_id, int time_eat, int time_sleep, int time_think)
{
    printf("Filósofo %d iniciou sua rotina\n", philo_id);    

    while(1)
    {
        eat(philo_id,time_eat);
        philo_sleep(philo_id, time_sleep);
        think(philo_id, time_think);
        // Implementação da lógica do filósofo (comer, pensar, etc.)
    }
    return NULL;
}
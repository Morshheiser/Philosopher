
#include "philo_library.h"

void *routine_philo(void *arg)
{
    t_philo *philo;

    philo = (t_philo*)arg; 
    printf("Filósofo %d iniciou sua rotina\n", philo->id);    
    if(philo->id % 2 == 0)
        usleep(500000);
    while(1)
    {
        eat(philo->table);
        philo_sleep(philo->id, philo->table->time_sleep);
        think(philo->id, philo->table->time_think);
        // Implementação da lógica do filósofo (comer, pensar, etc.)
    }
    printf("Filósofo %d terminou sua rotina\n", philo->id);
    return NULL;
}
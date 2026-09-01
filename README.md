*This project has been created as part of the 42 curriculum by fkruger.*

# Description
Simulate the dinining philosphers problem to demonstrate an understanding of threading and mutexes, and you know advance in the 42 CC.

## Data structures.

Each fork has a bool value as state indicating whether it is taken up.
This state is protected by pthread mutex.

Each philosopher has a struct which stores the last time it has eaten.
This time is the difference between the event and immediately before thread creation.
This time since the last meal too is protected by a mutex.
This is because the main thread checks this time of all philos to detected if they are over the time to die and detecteds the death this way.

The logging is also protected by mutex so only one log function is executed at a time.
This mechanism was extended to stop printing after a philosphor has died and to function as a killswitch for every philo thread to abort end early.

# Instructions
Run `make` to build the `./philo` program.

Run `./philo ${number_of_philosophers} ${time_to_die} ${time_to_eat} ${time_to_sleep}` to start an endless session of philosphers eating, sleeping and thinking. Each `time_to_*` argument is expected to be a whole positive number represeting millisecounds.

Alternatively you can add one more (positive) integer that represents the number of times each philospher has to eat at least to end the simulation (the happy ending).

# Resources
 - pthreads programming (ISBN 978-1-56592-115-3)
 - Wikipedia "Dining philosophers problem" (https://en.wikipedia.org/wiki/Dining_philosophers_problem)
 - man 7 pthreads
 - my fellow students were by far the most valuable resources <3 sancuta

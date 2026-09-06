*This project has been created as part of the 42 curriculum by fkruger.*

# Description
Simulate the dinining philosphers problem to demonstrate an understanding of threading and mutexes, and you know advance in the 42 CC.

This README assumes you have read the subject.pdf.

## Data structures.

Each fork has a bool value as state indicating whether it is taken up.
This state is protected by pthread mutex.

Each philosopher has a struct which stores the last time it has eaten.
This time is the difference between the event and immediately before thread creation.
This time since the last meal too is protected by a mutex.
This is because the main thread checks this time of all philos to detected if they are over the time to die and detecteds the death this way.

## Logging
The logging is also protected by mutex so only one log function is executed at a time.
This mechanism was extended to stop printing after a philosphor has died and to function as a return value to indicate if a philo should keep running or if the simulation should shutdown. See `log_queue.c` for the relevant code.

## Fork and waiting strategy for each philosphor
The philosphers with an uneven id take the right fork first, the others take the left fork first.
If the total number of philosphers is uneven then each philospher waits `("time to die" - "time to eat" - "time to sleep") / 2` after eating, this ensures that their neighbours who might be about to starve to grab a fork.
When starting the simulation these uneven ones also wait for `"time to eat" / 2` this gives every philospher a time slots.
This gives the even philospher a time slot to operate in and the uneven ones get their own timeslot.
Each philospher hopes to stay in their timeslot and never get into conflict with their neighbours this way.

# Instructions
Run `make` to build the `./philo` program.

Run `./philo ${number_of_philosophers} ${time_to_die} ${time_to_eat} ${time_to_sleep}` to start an endless session of philosphers eating, sleeping and thinking.
Each `time_to_*` argument is expected to be a whole positive number represeting millisecounds.
The maximum supported amount philophers in a simulation is 200.
The maximum value for a time parameter is 9999999999.

Alternatively you can add one more (positive) integer that represents the number of times each philospher has to eat at least to end the simulation (the happy ending).

# Resources
 - my fellow students were by far the most valuable resources, especially sancuta.
 - pthreads programming (ISBN 978-1-56592-115-3)
 - Wikipedia "Dining philosophers problem" (https://en.wikipedia.org/wiki/Dining_philosophers_problem)
 - man 7 pthreads
 - a visualizer to analyze the events, to debug the logic https://rom98759.github.io/Philosophers-visualizer/

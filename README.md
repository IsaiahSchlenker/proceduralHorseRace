include iostream, random and cstdlib

create a random dsitribution between 0 and 1

make a constant int NUM_HORSES
make a constant int TRACK_LENGTH

define the functions advance, printLane and isWinner

# main()

make a boolean called keepGoing
init keepgoing true
create an array of 5 zeros called horses

while keepGoing
    for each horse
        advance the horse if the coin flips heads
        print that horse's lane
        if the horse won
            print that the horse won
    have the user hit enter to run through the while again

# advance()

flip the coin
if it lands heads
    add one to the horse position

# printLane()

for each spot on the track
    if it is where the horse is 
        print the horse name
    else
        print a .
end the line

# isWinner()

if the horse reached the end of the track
    return true
else
    return false

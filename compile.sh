FLAGS="-Wall -Wextra -pedantic -std=c99"
INCLUDES="propag.c math.c toolbox.c"
LIBS=("m")

LFLAGS_ARR=("${LIBS[@]/#/-l}")
LFLAGS=$( IFS=$' '; echo "${LFLAGS_ARR[*]}" )

gcc -o a main.c $INCLUDES $FLAGS $LFLAGS

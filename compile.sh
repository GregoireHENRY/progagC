FLAGS="-Wall -Wextra -pedantic -std=c99"
FILES=("main.c" "propag.c" "math.c" "toolbox.c")
LIBS=("m")

LFLAGS_ARR=("${LIBS[@]/#/-l}")
LFLAGS=$( IFS=$' '; echo "${LFLAGS_ARR[*]}" )

INCLUDES_ARR=("${FILES[@]/#/src/}")
INCLUDES=$( IFS=$' '; echo "${INCLUDES_ARR[*]}" )

gcc -o a $INCLUDES $FLAGS $LFLAGS

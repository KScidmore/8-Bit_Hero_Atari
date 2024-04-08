#include <osbind.h>
#include "globals.h"

long old_ssp;

void enter_super(){

    old_ssp = Super(0);

}

void exit_super(){

    Super(old_ssp);

}
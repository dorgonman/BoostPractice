// Copyright 2013 Joshua Dentoyan
// showing how to to use timers in MSM
// distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// vending_machine.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cctype>                       
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include "vending_machine.h"


int main()
{
    jsm::state_machine<vending_machine_> sm;
    sm.set_debug(false);
    sm.start();
    process(sm);
    sm.stop();
    return 0;
}
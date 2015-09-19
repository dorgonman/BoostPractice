// Copyright 2013 Joshua Dentoyan
// showing how to to use timers in MSM
// distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// vending_machine.cpp : Defines the entry point for the console application.
//

#include "GUIViewFSM.h"


#include "HorizonLog.h"
#include "HorizonCore.h"
int main()
{
    horizon::HorizonCore::GetInstance()->init();
    HORIZON_INFO << "TEST";
    //horizon::log::HORIZON_DEBUG_F << "test";
  
   // startGUIViewFSM();
    return 0;
}
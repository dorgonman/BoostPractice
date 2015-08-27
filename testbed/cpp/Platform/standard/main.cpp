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
#include "StateMachineContext.h"

#include "jsm.h"

namespace horizon{
    //list of event
    namespace events{
        class GameStartEvent{};
        class GameExitToTitleViewEvent{};
    }

    // The list of FSM states
    class UTitleView : public boost::msm::front::state < >{
    public:
        // empty implementation for the states not wishing to define an entry condition
        // will not be called polymorphic way
        template <class Event, class FSM>
        void on_entry(Event const& e, FSM &fsm){
            std::cout << "entering: UTitleView" << std::endl;
        }

        template <class Event, class FSM>
        void on_exit(Event const& e, FSM& fsm){
            std::cout << "on_exit: UTitleView" << std::endl;
        }
    };

    class UHomeView : public boost::msm::front::state < >{
    public:
        // empty implementation for the states not wishing to define an entry condition
        // will not be called polymorphic way
        template <class Event, class FSM>
        void on_entry(Event const& e, FSM &fsm){
            std::cout << "entering: UHomeView" << std::endl;
        }

        template <class Event, class FSM>
        void on_exit(Event const& e, FSM& fsm){
            std::cout << "on_exit: UHomeView" << std::endl;
        }
    };



    class UGUIViewFSM : public boost::msm::front::state_machine_def < UGUIViewFSM > {
    private:
       

    public:
        template <class TFSMContext>
        UGUIViewFSM(TFSMContext &m){

        };
        // the initial state of the SM. Must be defined
        typedef UTitleView initial_state;
        struct transition_table : boost::mpl::vector<
            //   Start            Event                     Next
            _row<UTitleView, events::GameStartEvent, UHomeView>,
            _row<UHomeView,  events::GameExitToTitleViewEvent, UTitleView>
        >{};


    };

}

#include <exception>
int main()
{
    horizon::StateMachineContext<horizon::UGUIViewFSM> sm;

    sm.start();
    sm.processEvent(horizon::events::GameStartEvent());
    sm.stop();
   /* jsm::state_machine<vending_machine_> sm;
    sm.set_debug(false);
    sm.start();
    process(sm);
    sm.stop();*/
    return 0;
}
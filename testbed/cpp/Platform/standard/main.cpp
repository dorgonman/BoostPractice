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

namespace horizon{
    template<class TMachineType>
    class UStateMachine{
        typedef boost::msm::back::state_machine<TMachineType> StateMachineImp;
    public:

        template<class TEventType>
        void operator() (const TEventType &e);

        StateMachineImp &machine() {
            return *m_machine;
        }

        void setDebug(bool b) {
            m_bDebug = b;
        }

        void start() {
            m_machine->start();
        }

        void stop() {
            //timer_service().stop();
           // join();
        }

        void printState() {
            int cs = m_machine->current_state()[0];
            std::cout << "current_state: " << cs << std::endl;
        }
    private:

        boost::shared_ptr<StateMachineImp> m_machine;
        bool m_bDebug;
    };


    template<class TMachineType> template<class TEventType>
    inline void UStateMachine<TMachineType>::operator() (const TEventType &e)
    {
        boost::mutex::scoped_lock scoped_lock(mutex);
        using namespace std;
        if (m_bDebug)
            cout << "process: " << typeid(e).name() << endl;
        m_machine->process_event(e);
        if (m_bDebug)
            print_state();
    }

    // The list of FSM states
    class UInitView : public msm::front::state<>
    {
        // empty implementation for the states not wishing to define an entry condition
        // will not be called polymorphic way
        template <class TEventType, class FSM>
        void on_entry(Event const& e, FSM &fsm){}

        template <class Event, class FSM>
        void on_exit(Event const&, FSM&){}
    };




    class UGUIViewManager : public msm::front::state_machine_def<UGUIViewManager>{
    public:
        UGUIViewManager* GetInstance(){
            static UGUIViewManager fsm;
            return &fsm;
        };
   
    public:
        // the initial state of the SM. Must be defined
        typedef UInitView initial_state;


    };
};

int main()
{
    horizon::UStateMachine<horizon::UGUIViewFSM> sm;

    sm.start();

   /* jsm::state_machine<vending_machine_> sm;
    sm.set_debug(false);
    sm.start();
    process(sm);
    sm.stop();*/
    return 0;
}
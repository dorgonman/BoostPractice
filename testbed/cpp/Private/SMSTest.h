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

    class UGUIView : public boost::msm::front::state < > {
    public:
        UGUIView(){

        }
        // empty implementation for the states not wishing to define an entry condition
        // will not be called polymorphic way
        template <class Event, class FSM>
        void on_entry(Event const& e, FSM &fsm){
            OnEnter();
        }

        template <class Event, class FSM>
        void on_exit(Event const& e, FSM& fsm){
            OnExit();
        }

    protected:
        virtual void OnEnter() = 0;
        virtual void OnExit() = 0 ;
    };

    // The list of FSM states
    class UTitleView : public UGUIView{
    public:
        UTitleView(){
        
        }
        virtual void OnEnter() override{
            std::cout << "entering: UTitleView" << std::endl;
        }
      

        virtual void OnExit() override{
            std::cout << "OnExit: UTitleView" << std::endl;
        }
    };

    class UHomeView : public UGUIView{
    public:
        UHomeView(){
        
        }

        virtual void OnEnter() override{
            std::cout << "entering: UHomeView" << std::endl;
        }


        virtual void OnExit() override{
            std::cout << "OnExit: UHomeView" << std::endl;
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

void start(){
    horizon::StateMachineContext<horizon::UGUIViewFSM> sm;

    sm.start();
    sm.processEvent(horizon::events::GameStartEvent());
    sm.processEvent(horizon::events::GameExitToTitleViewEvent());
    sm.stop();
}

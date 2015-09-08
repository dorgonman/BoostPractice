#include "GUIViewFSM.h"


void startGUIViewFSM(){
    horizon::StateMachineContext<horizon::UGUIViewFSM> sm;

    sm.start();
    sm.processEvent(horizon::events::GameStartEvent());
    sm.processEvent(horizon::events::GameExitToTitleViewEvent());
    sm.stop();
}

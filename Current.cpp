#include "Current.h"

Current::Current(PolycodeView *view) {
	core = new POLYCODE_CORE(view, 640,480,false,false,0,0,90);
	CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);
	CoreServices::getInstance()->getResourceManager()->addDirResource("Resources", false);
    CoreServices::getInstance()->getRenderer()->setClippingPlanes(0.1, 5000);   // Set far plane very far: avoid weird visual effects!
    
    menu = new MainMenu(core, new Sound("menuRotate.ogg"), new Sound("menuSelect.ogg"), new Sound("menuSelectLocked.ogg"));
}

Current::~Current() {}

bool Current::Update(){
    return menu->Update();
}

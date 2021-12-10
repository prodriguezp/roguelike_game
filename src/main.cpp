
#include "Engine.hpp"
int main() {
   Engine engine;
   while ( !TCODConsole::isWindowClosed() ) {
      engine.Update();
      engine.Render();
   }
   return 0;
}


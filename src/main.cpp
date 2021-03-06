#include<iostream>
#include <math.h>
#include <stdlib.h>

#include "SDL2/SDL.h"
#include "Screen.h"
#include "FractalCreator.h"
#include "Zoom.h"

using namespace Graphics;
using namespace std;

int main() {
  Screen screen;

  if(screen.init() == false){
    cout << "Error initializing SDL" << endl;
  }


  Fractal::FractalCreator fractalCreator(500,screen.SCREEN_WIDTH, screen.SCREEN_HEIGHT, &screen);
  //Fractal::FractalCreator bufferFractal(500, screen.SCREEN_WIDTH, screen.SCREEN_HEIGHT, &screen);

  fractalCreator.addRange(0.0, RGB(0,0,0));
  fractalCreator.addRange(0.3, RGB(206, 95, 237));
  fractalCreator.addRange(0.5, RGB(88, 237, 217));
  fractalCreator.addRange(1.0, RGB(255, 240, 36));

  // bufferFractal.addRange(0.0, RGB(0,0,0));
  // bufferFractal.addRange(0.3, RGB(206, 95, 237));
  // bufferFractal.addRange(0.5, RGB(88, 237, 217));
  // bufferFractal.addRange(1.0, RGB(255, 240, 36));;


  //bufferFractal.run();
  fractalCreator.run();

  SDL_Event event;

  while(true){

    //screen.clear();


    // check for mouse events
    if(SDL_PollEvent(&event)){
      if(event.type == SDL_MOUSEBUTTONDOWN){
        cout << event.motion.x << ", " << event.motion.y << endl;
        screen.clear();
        screen.bufferSwap();
        screen.update();

        //bufferFractal.addZoom(Fractal::Zoom(event.motion.x, event.motion.y, 0.1));
        //bufferFractal.run();

        fractalCreator.addZoom(Fractal::Zoom(event.motion.x, event.motion.y, 0.1));
        fractalCreator.run();
      }
    }

    // check for quit event
    if(screen.quit()){
      break;
    }
  }

  screen.close();
  
  return 0;
}
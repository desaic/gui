#pragma once
#include <nanogui/nanogui.h>
#include <GLFW/glfw3.h>
#include "Render.hpp"

class ViewerGUI
{
public:

  enum test_enum {
    Item1 = 0,
    Item2,
    Item3
  };
  
  bool bvar;
  int slice0, slice;
  double dvar;
  float fvar;
  nanogui::Color colval;
  test_enum enumval;
  std::string strval;

  ViewerGUI() : bvar(true), slice0(0), slice(0), 
    dvar(3.14), fvar(3.14f),
    colval(0.5f, 0.5f, 0.7f, 1.f) ,
    enumval(Item2),  strval("string"),
    screen(nullptr), window(0),
    render(0){}
  
  void init();
  void setWindow(GLFWwindow * w) { window = w; }
  void drawContent() {
    if (!render) {
      return;
    }
    if (slice0 != slice) {
      slice0 = slice;
      if (render->meshes.size() > 0) {
        render->emEvent[0].eventType = Render::MOVE_SLICE_EVENT;
        render->emEvent[0].slice = slice;
      }
    }
    render->drawContent();
  }
  void ButtonCBOpen();
  nanogui::Screen *screen;
  GLFWwindow* window;
  Render * render;
};

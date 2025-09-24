#pragma once

struct UIElement {
  void *classptr;
  struct Stage *stage;
  struct UIElementContainer *parent;
  short show;
  short isModal;
  short isSelected;
  short containsMouse;
  int x;
  int y;
  int w;
  int h;
};
struct UIElementContainer {
  struct UIElement asUIElement;
  struct STDVector children; // UIElement*,std::allocator<UIElement*>
};
struct Stage {
  struct UIElementContainer asUIElementContainer;
};

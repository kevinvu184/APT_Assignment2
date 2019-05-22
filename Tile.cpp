#include "Tile.h"

Tile::Tile(Colour c, Shape s) {
  this->colour = c;
  this->shape = s;
}

Tile::Tile(const Tile &t) {
  colour = t.colour;
  shape = t.shape;
}

Tile::Tile() {
  shape = 0;
  colour = ' ';
}

Shape Tile::getShape() {
  return shape;
}

Colour Tile::getColour() {
  return colour;
}

void Tile::setShape(Shape s) {
  shape = s;
}

void Tile::setColour(Colour c) {
  colour = c;
}

bool Tile::compareTile(Tile *t) {
  bool result = false;
  if (this->colour == t->getColour() && this->shape == t->getShape()) {
    result = true;
  }
  return result;
}

bool Tile::isSameColour(const Tile &t) {
  return colour == t.colour;
}

bool Tile::isSameShape(const Tile &t) {
  return shape == t.shape;
}

std::ostream &operator<<(std::ostream &out, const Tile &t) {
  out << t.colour << std::to_string(t.shape);
  return out;
}

//std::ostream &operator<<(std::ostream &out, const Tile &t) {
//  std::string setColour = "";
//  if (t.colour == RED)
//    setColour = SET_RED;
//  if (t.colour == ORANGE)
//   setColour = SET_ORANGE;
//  if (t.colour == YELLOW)
//    setColour = SET_YELLOW;
//  if (t.colour == GREEN)
//    setColour = SET_GREEN;
//  if (t.colour == BLUE)
//    setColour = SET_BLUE;
// if (t.colour == PURPLE)
//    setColour = SET_PURPLE;

//  out << setColour << t.colour << std::to_string(t.shape) << RESET_COLOUR;
//  return out;
//}

// std::ostream &operator<<(std::ostream &out, const Tile &t) {
// 	std::string setColour = "";
// 	if (t.colour == RED)
// 		setColour = SET_RED;
// 	if (t.colour == ORANGE)
// 		setColour = SET_ORANGE;
// 	if (t.colour == YELLOW)
// 		setColour = SET_YELLOW;
// 	if (t.colour == GREEN)
// 		setColour = SET_GREEN;
// 	if (t.colour == BLUE)
// 		setColour = SET_BLUE;
// 	if (t.colour == PURPLE)
// 		setColour = SET_PURPLE;

// 	if (t.shape == CIRCLE)
// 		out << setColour << SET_CIRCLE << RESET_COLOUR;
// 	if (t.shape == STAR_4)
// 		out << setColour << SET_STAR_4 << RESET_COLOUR;
// 	if (t.shape == DIAMOND)
// 		out << setColour << SET_DIAMOND << RESET_COLOUR;
// 	if (t.shape == SQUARE)
// 		out << setColour << SET_SQUARE << RESET_COLOUR;
// 	if (t.shape == STAR_6)
// 		out << setColour << SET_STAR_6 << RESET_COLOUR;
// 	if (t.shape == CLOVER)
// 		out << setColour << SET_CLOVER << RESET_COLOUR;
// 	return out;
// }

Tile &Tile::operator=(const Tile &t) {
  colour = t.colour;
  shape = t.shape;
  return *this;
}

bool operator==(const Tile &t1, const Tile &t2) {
  return t1.colour == t2.colour && t1.shape == t2.shape;
}

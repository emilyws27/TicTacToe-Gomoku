#include "pieces.h"
//contains constructor for game_pieces objs

game_pieces::game_pieces() : name(" "), appearance(" ") {}
game_pieces::game_pieces(std::string name, std::string appearance) :name(name), appearance(appearance) {
}
//
// Created by Ivo Georgiev on 11/22/15.
//

#ifndef PA5GAME_SIMPLE_H
#define PA5GAME_SIMPLE_H

#include "Game.h"
#include "Agent.h"

namespace Gaming {

    class Simple : public Agent {
    private:
        static const char SIMPLE_ID;
        bool __bias;
        void changeBias() { __bias = !__bias;}

    public:
        Simple(const Game &g, const Position &p, double energy);
        ~Simple();

        PieceType getType() const override { return PieceType::SIMPLE; }
        char getTypeId() const override { return SIMPLE_ID; }

        void print(std::ostream &os) const override;

        ActionType takeTurn(const Surroundings &s) const override;

    };
}

#endif //PA5GAME_SIMPLE_H

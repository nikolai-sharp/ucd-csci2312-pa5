//
// Created by Ivo Georgiev on 11/22/15.
//

#ifndef PA5GAME_AGENT_H
#define PA5GAME_AGENT_H

#include "Game.h"
#include "Piece.h"

namespace Gaming {

    class Agent : public Piece {

    protected:
        double __energy;
        static const ActionType surroundingToAction[9];

    public:
        static const double AGENT_FATIGUE_RATE;

        Agent(const Game &g, const Position &p, double energy);
        ~Agent();

        double getEnergy() const { return __energy; };
        void addEnergy(double e) { __energy += e; };

        void age() override final {__energy -= AGENT_FATIGUE_RATE;};

        bool isViable() const override final { return !isFinished() && __energy > 0.0; };

        Piece &operator*(Piece &other) override final;
        Piece &interact(Agent *other) override final;
        Piece &interact(Resource *other) override final;

    };

}


#endif //PA5GAME_AGENT_H

/*
------------------------- PragmaEngine BY L7SSHA | ALL RIGTS RESERVED -------------------------
PragamEngine version 3.0
Copyright (c) 2016 Szymon "l7ssha" Uglis

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.
Permission is granted to no one to use this software for any purpose,
including commercial application

------------------------- PragmaEngine BY L7SSHA | ALL RIGTS RESERVED -------------------------
*/
#pragma once

#include <vector>

namespace PragmaEngine {

    class ParticleBatch2D;
    class SpriteBatch;

    class ParticleEngine2D {
    public:
        ParticleEngine2D();
        ~ParticleEngine2D();

        // After adding a particle batch, the ParticleEngine2D becomes
        // responsible for deallocation.
        void addParticleBatch(ParticleBatch2D* particleBatch);

        void update(float deltaTime);

        void draw(SpriteBatch* spriteBatch);

    private:
        std::vector<ParticleBatch2D*> m_batches;
    };

}
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
#include "ParticleEngine2D.h"

#include "ParticleBatch2D.h"
#include "SpriteBatch.h"

namespace PragmaEngine {


    ParticleEngine2D::ParticleEngine2D() {
        // Empty
    }

    ParticleEngine2D::~ParticleEngine2D() {
        for (auto& b : m_batches) {
            delete b;
        }
    }

    void ParticleEngine2D::addParticleBatch(ParticleBatch2D* particleBatch) {
        m_batches.push_back(particleBatch);
    }

    void ParticleEngine2D::update(float deltaTime) {
        for (auto& b : m_batches) {
            b->update(deltaTime);
        }
    }

    void ParticleEngine2D::draw(SpriteBatch* spriteBatch) {
        for (auto& b : m_batches) {
            spriteBatch->begin();
            b->draw(spriteBatch);
            spriteBatch->end();
            spriteBatch->renderBatch();
        }
    }


}
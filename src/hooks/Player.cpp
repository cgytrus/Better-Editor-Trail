#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include "../trail/Trail.hpp"

using namespace geode::prelude;

class $modify(Player, PlayerObject) {
    bool pushButton(PlayerButton p0) {
        if (!m_editorEnabled) return PlayerObject::pushButton(p0);
        Trail::startMove(this, p0);
        bool ret = PlayerObject::pushButton(p0);
        Trail::endMove(this, static_cast<PlayerButton>(0));
        return ret;
    }

    bool releaseButton(PlayerButton p0) {
        if (!m_editorEnabled) return PlayerObject::releaseButton(p0);
        Trail::startMove(this, static_cast<PlayerButton>(0));
        bool ret = PlayerObject::releaseButton(p0);
        Trail::endMove(this, p0);
        return ret;
    }

    void update(float dt) {
        if (!m_editorEnabled) return PlayerObject::update(dt);
        Trail::startMove(this, static_cast<PlayerButton>(0));
        PlayerObject::update(dt);
    }
};

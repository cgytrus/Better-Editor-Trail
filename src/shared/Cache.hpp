#pragma once

namespace Cache {
    inline cocos2d::CCLayer* trailLayer = nullptr;

    inline cocos2d::CCDrawNode* trailDraw = nullptr;
    inline cocos2d::CCDrawNode* indicatorDraw = nullptr;

    inline bool trailRendering = false;

    inline cocos2d::ccColor4F p1TrailCol;
    inline cocos2d::ccColor4F p2TrailCol;
}

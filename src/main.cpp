#include <Geode/Geode.hpp>
#include <Geode/modify/RateStarsLayer.hpp>
#include <Geode/Bindings.hpp>

using namespace geode::prelude;

class $modify(RateStarsLayer) {
    bool init(int first, bool second, bool third) {
        bool result = RateStarsLayer::init(first, second, third);
        
        CCLayer* layer = typeinfo_cast<CCLayer*>(this->getChildren()->objectAtIndex(0));
        CCLabelBMFont* label = typeinfo_cast<CCLabelBMFont*>(layer->getChildren()->objectAtIndex(1));

        std::string labelText = label->getString();
        if (labelText == "Rate Stars" || labelText == "Rate Moons") {
            label->setString(("Dev: " + labelText).c_str());
        }
        return result;
    }
};
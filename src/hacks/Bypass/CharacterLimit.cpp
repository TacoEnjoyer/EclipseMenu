#include <modules/gui/gui.hpp>
#include <modules/hack/hack.hpp>
#include <modules/config/config.hpp>

#include <Geode/modify/CCTextInputNode.hpp>

namespace eclipse::hacks::Bypass {

    class CharLimit : public hack::Hack {
        void init() override {
            auto tab = gui::MenuTab::find("Bypass");
            tab->addToggle("Character Limit Bypass", "bypass.charlimit")
                ->handleKeybinds()
                ->setDescription("Allows you to bypass the character limit of any text field");
        }

        [[nodiscard]] const char* getId() const override { return "Character Limit Bypass"; }
    };

    REGISTER_HACK(CharLimit)

    class $modify(CCTextInputNode) {
        void updateLabel(gd::string str) {
            if (config::get<bool>("bypass.charlimit", false)) setMaxLabelLength(99999);
            CCTextInputNode::updateLabel(str);
        }
    };

}

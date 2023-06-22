/*
  ==============================================================================

    PlayerWindow.h
    Created: 9 Jun 2023 12:59:58am
    Author:  drive

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace akasha {
    class PlayerWindow : public juce::DocumentWindow {
    public:
        PlayerWindow(juce::String name);
        ~PlayerWindow() override;
        
        void closeButtonPressed() override;
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PlayerWindow);
    };
}
#pragma once

#include <JuceHeader.h>
#include "PlayerWindow.hh"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    std::unique_ptr<akasha::PlayerWindow> playerWindow;

    juce::TextButton audioPlayerButton;
    auto openMusicPlayer() -> void;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

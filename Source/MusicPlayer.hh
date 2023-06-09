/*
  ==============================================================================

    MusicPlayer.h
    Created: 8 Jun 2023 8:43:06pm
    Author:  Admin

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
namespace akasha {
    const auto musicPlayerName = "Kanam Player";

    class MusicPlayer  : public juce::Component {
    public:
        MusicPlayer();
        ~MusicPlayer() override;

        void paint (juce::Graphics&) override;
        void resized() override;

    private:
        juce::ImageButton playButton;
        juce::ImageButton pauseButton;
        juce::ImageButton nextButton;
        juce::ImageButton prevButton;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MusicPlayer)
    };
}
